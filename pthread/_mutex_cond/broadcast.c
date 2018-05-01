
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define N 5
	pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER ;
	pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void* pthread_fun1(void *arg)
{
	int n = *(int*)arg;
	pthread_mutex_lock(&mutex);
	printf("This is [%d] pthread is sleep \n",n);
	pthread_cond_wait(&cond,&mutex);
	printf("This is [%d] pthead  is wake up \n",n);
	pthread_mutex_unlock(&mutex);
}
void* signal_pthread(void *arg)
{
	/*
	pthread_cond_signal(&cond);
	sleep(1);
	pthread_cond_signal(&cond);
	sleep(1);
	pthread_cond_signal(&cond);
	sleep(1);
	pthread_cond_signal(&cond);
	sleep(1);
	pthread_cond_signal(&cond);
	sleep(1);
	*/
	pthread_cond_broadcast(&cond);
}

int main()
{
	pthread_t tid[N];
	int i;
	for(i=0;i<N;i++)
	{
		pthread_create(&tid[i],NULL,(void *)pthread_fun1,&i);
		sleep(1);
	}
	pthread_t tid1;
	pthread_create(&tid1,NULL,(void*)signal_pthread,NULL);
	for(i=0;i<N;i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_join(tid1,NULL);
}

