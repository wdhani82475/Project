#include<stdio.h>
#include<unistd.h>
void fun()
{
	printf("pid = %d\n",getpid());
}
int main()
{
	printf("pid = %d\n",getpid());
	printf("ppid = %d\n",getppid());
	fun();
	return 0;
}
/*
int main()
{
	int i=0;
	for(;i<100;i++)
	{
		printf("i=%d\n",i);
		sleep(1);
	}
	return 0;
}
*/
