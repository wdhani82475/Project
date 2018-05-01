#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void* thread_fun1()
{
	pthread_mutex_lock(&mutex);
	printf("This is thread_fun1\n");
//	sleep(5);
//	pthread_mutex_unlock(&mutex);
	pthread_cond_wait(&cond,&mutex);
	printf("pthread_fun1 Finish.\n");
}
void* thread_fun2()
{
	/*
	 int res = pthread_mutex_trylock(&mutex);
	if(res == 0)
	{
		printf("pthread_fun2 Lock OK.\n");
	}
	else
		printf("pthreaf_fun2 Lock Fail.\n");
	*/
	pthread_mutex_lock(&mutex);
	printf("This is thread_fun2\n");
	printf("pthread_fun2 Finish.\n");
	pthread_cond_signal(&cond);
	printf("aaaaaaaaaaaaaaa\n");
	pthread_mutex_unlock(&mutex);
}
int main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,(void*)thread_fun1,NULL);
	sleep(1);
	pthread_create(&tid2,NULL,(void*)thread_fun2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}

