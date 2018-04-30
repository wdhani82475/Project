#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
void* fun(void* arg)
{
	int n = * (int*)arg;
	printf("This is [%d] Pthread\n",n);
	pthread_exit("Child Pthread Success Finish.\n");
	
}
int main()
{
	pthread_t tid[10];
	int res,i;
	for(i=0;i<10;i++)
	{
		res = pthread_create(&tid[i],NULL,(void*)fun,&i);
		if(res != 0)
		{
			perror("Create");
			exit(1);
		}
		sleep(1);
	}
	char *Exit_Code ;
	for(i=0;i<10;i++)
	{
		pthread_join(tid[i],(void **)&Exit_Code);
		printf("Exit_Code>%s\n",Exit_Code);
	}
	return 0;
}
