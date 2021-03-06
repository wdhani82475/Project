#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_rwlock_t rwlock;
void *Fun1(void* arg)
{
	//pthread_rwlock_wrlock(&rwlock);
	pthread_rwlock_rdlock(&rwlock);
	printf("This is Fun1 pthread.\n");
}
void *Fun2(void* arg)
{
	pthread_rwlock_rdlock(&rwlock);
	printf("This is Fun2 pthread.\n");
}
int main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,Fun1,NULL);
	sleep(1);
	pthread_create(&tid2,NULL,Fun2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
