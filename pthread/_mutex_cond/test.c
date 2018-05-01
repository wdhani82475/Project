/*利用两个线程处理10以内的数字，A函数打印奇数，B函数打印偶数*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define N 10
static int i =1;
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t even = PTHREAD_COND_INITIALIZER;
pthread_cond_t uneven = PTHREAD_COND_INITIALIZER;
void* Afun()
{
	while(i<=N)
	{
		pthread_mutex_lock(&mutex);
		if(i%2 != 0)
		{
			printf("In Afun %d\n",i);
			++i;
			pthread_cond_signal(&uneven);
		}
		else
		{
			pthread_cond_wait(&even,&mutex);
		}
		pthread_mutex_unlock(&mutex);
	}
}
void* Bfun()
{
	while(i<=N)
	{
		pthread_mutex_lock(&mutex);
		if(i%2 == 0)
		{ 
			printf("In Bfun() %d\n ",i);
			++i;
			pthread_cond_signal(&even);
		}
		else
		{
			pthread_cond_wait(&uneven,&mutex);
		}
		pthread_mutex_unlock(&mutex);
	}
}
int main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,Afun,NULL);
	pthread_create(&tid2,NULL,Bfun,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
