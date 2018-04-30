
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* fun(void *arg)
{
	int n = *(int *)arg;
	int i;
	for(i=0;i<n;i++)
	{
		printf("This is Child Pthread.\n");
	}
	printf("Chlid Pthread id = %d\n",pthread_self());
	//pthread_exit(NULL);
	pthread_exit("Child Pthread Success Finish");
}
int main()
{
	pthread_t tid;
	printf("Main Pthread id = %d\n",tid);
	int i;
	for(i=0;i<10;i++)
	{
		printf("This is Main Thread.\n");
	}
	int n=2;
	pthread_create(&tid,NULL,(void*)fun,&n);
	//pthread_join(tid,NULL);
	char * Exit_Code;
	pthread_join(tid,(void **)&Exit_Code);
	printf("In Main:%s\n",Exit_Code);
	return 0;
}

