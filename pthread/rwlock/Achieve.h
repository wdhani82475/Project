#include"my_pthread_rwlock.h"
enum{ EINVAL =1};
my_pthread_rwlock_rdlock(my_pthread_rwlock_t *rw)
{
	int result;
	if(rw->rw_magic != RW_MAGIC)
		return EINVAL;
	//加锁失败
	if((result = pthread_mutex_lock(&rw->rw_mutex ))!=0)
		return result;
	//有线程正在写 读阻塞
	while(rw->rw_refcount<0)
	{
		rw->rw_nwaitreaders++;
		result = pthread_cond_wait(&rw->rw_condreaders,&rw->rw_mutex);
		rw->rw_nwaitreaders--;
		if(result != 0)
			break;
	}
	if(result == 0)
	{
		rw->rw_refcount++;
	}
	pthread_mutex_unlock(&rw->rw_mutex);
	return result;
}

my_pthread_rwlock_wrlock(my_pthread_rwlock_t *rw)
{
	int result;
	if(rw->rw_magic != RW_MAGIC)
		return EINVAL;
	if((result = pthread_mutex_lock(&rw->rw_mutex))!=0)
		return result;
	//有读 或有写    有读的等待
	while(rw->rw_refcount !=0||rw->rw_nwaitreaders>0)
	{
		rw->rw_nwaitwriters++;
		result = pthread_cond_wait(&rw->rw_condwriters,&rw->rw_mutex);
		rw->rw_nwaitwriters--;
		if(result != 0)
			break;
	}
	if(result == 0)
		rw->rw_refcount = -1;
	pthread_mutex_unlock(&rw->rw_mutex);
	return result;
}

my_pthread_rwlock_unlock(my_pthread_rwlock_t *rw)
{
	int result;
	if(rw->rw_magic != RW_MAGIC)
		return EINVAL;
	if((result = pthread_mutex_lock(&rw->rw_mutex))!=0)
		return result;
	if(rw->rw_refcount>0)
	{
		rw->rw_refcount--;
	}
	else if(rw->rw_refcount == -1)
	{
		rw->rw_refcount = 0;
	}
	else
	{
		printf("unlock wrlock fail\n");
	}
	 if(rw->rw_nwaitreaders>0)
	{
		result =pthread_cond_broadcast(&rw->rw_condreaders);
	}
	 else if(rw->rw_nwaitwriters>0)
	{
		if(rw->rw_refcount == 0)
			result = pthread_cond_signal(&rw->rw_condwriters);
	}
	pthread_mutex_unlock(&rw->rw_mutex);
	return result;
}


