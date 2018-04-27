#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid>0)
	{
		printf("Parent Wait...\n");
		//sleep(4);
		int status;
		wait(&status);
		printf("This is Parent\n");
	}
	else if(pid == 0)
	{
		printf("Child Sleep...\n");
		sleep(2);
		printf("This is Child\n");
	}
	else
	{
		perror("fork");
	}
	return 0;
}
