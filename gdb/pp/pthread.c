#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* fun1(void *arg)
{
	int n = *(int *)arg;
	printf("This is [%d] pthread\n",n);
}
void* fun(void* arg)
{
	printf("This is fun \n");
}
int main()
{
	pthread_t pid[5],pid1;
	int i;
	for(i=0;i<5;i++)
	{
		pthread_create(&pid[i],NULL,(void*)fun1,&i);
		sleep(1);
	}
	pthread_create(&pid1,NULL,(void*)fun,NULL);
	for(i=0;i<5;i++)
	{
		pthread_join(pid[i],NULL);
	}
	pthread_join(pid1,NULL);
		return 0;
}

