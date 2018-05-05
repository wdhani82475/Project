#ifndef __MY_PTHREAD_RWLOCK_H__
#define __MY_PTHREAD_RWLOCK_H__
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
typedef struct
{
	pthread_mutex_t rw_mutex;
	pthread_cond_t rw_condreaders;
	pthread_cond_t rw_condwriters;
	int rw_magic;
	int rw_nwaitwriters;
	int rw_nwaitreaders;
	int rw_refcount;// -1 wr   0    >0 rd
}my_pthread_rwlock_t ;

#define RW_MAGIC 0x12345678
#define PTHREAD_RWLOCK_INITIALIZER {PTHREAD_MUTEX_INITIALIZER,\
PTHREAD_COND_INITIALIZER,\
PTHREAD_COND_INITIALIZER,\
RW_MAGIC, 0,0,0}
int my_pthread_rwlock_rdlock(my_pthread_rwlock_t *rw);
int my_pthread_rwlock_wrlock(my_pthread_rwlock_t *rd);
int my_pthread_rwlock_unlock(my_pthread_rwlock_t *lc);
#endif
