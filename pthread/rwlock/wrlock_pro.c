#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define N 5
pthread_rwlock_t rwlock;
void* Fun1(void *arg)
{

	pthread_rwlock_wrlock(&rwlock);
	printf("This is Fun1 pthread .\n");
	sleep(13);
	pthread_rwlock_unlock(&rwlock);
}
void* Fun2(void *arg)
{
	int n = *(int *)arg;
	printf("This is [%d] pthread rdlock \n",n);
	pthread_rwlock_rdlock(&rwlock);
	printf("[%d]pthread get rdlock.\n",n);
	pthread_rwlock_unlock(&rwlock);
}

void* Fun3(void *arg)
{

	int n = *(int *)arg;
	printf("This is [%d] pthread wrlock\n",n);
	pthread_rwlock_wrlock(&rwlock);
	printf("[%d]pthread get wrlock\n",n);
	pthread_rwlock_unlock(&rwlock);
}

int main()
{
	pthread_t tid1,tid2[N],tid3[N];
	pthread_create(&tid1,NULL,Fun1,NULL);
	sleep(1);
	int i;
	for(i=0;i<N;i++)
	{
		pthread_create(&tid2[i],NULL,Fun2,&i);
		sleep(1);
	}
	for(i=0;i<N;i++)
	{
		pthread_create(&tid3[i],NULL,Fun3,&i);
		sleep(1);
	}
		pthread_join(tid1,NULL);
	for(i=0;i<N;i++)
	{
		pthread_join(tid2[i],NULL);
	}
	for(i=0 ;i<N;i++)
	{
		pthread_join(tid3[i],NULL);
	}
		return 0;
}


