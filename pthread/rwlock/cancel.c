#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include"my_pthread_rwlock.h"
#include"Achieve.h"
my_pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
void *Fun1(void* arg)
{
	pthread_t tid =*(pthread_t *)arg;
	printf("This is Fun1 pthread.\n");
	pthread_cancel(tid);
	printf("This is Fun1 pthread Wait up\n");
}
void* clean_up(void *arg)
{
	printf("This is clean up.\n");
}

void *Fun2(void* arg)
{
	my_pthread_rwlock_wrlock(&rwlock);
	printf("This is Fun2 pthread.\n");
	pthread_cleanup_push(clean_up,NULL);
	pthread_exit(NULL);
	sleep(5);
	pthread_cleanup_pop(1);

	my_pthread_rwlock_unlock(&rwlock);
	printf("This is Fun2 pthread Wait up.\n");
}
void *Fun3(void* arg)
{
	my_pthread_rwlock_rdlock(&rwlock);
	printf("This is Fun3 pthread.\n");
	my_pthread_rwlock_unlock(&rwlock);
	printf("This is Fun3 pthread Wait up.\n");
}

int main()
{
	pthread_t tid1,tid2,tid3;
	pthread_create(&tid2,NULL,Fun2,NULL);
	sleep(1);
	//pthread_create(&tid3,NULL,Fun3,NULL);
	pthread_create(&tid1,NULL,Fun1,&tid2);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	//pthread_join(tid3,NULL);
	return 0;
}
