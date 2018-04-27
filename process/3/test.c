#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid = vfork();
	if(pid>0)
	{
		printf("This is Parent.\n");
	}
	else if(pid == 0)
	{
		printf("This is Child.\n");
		exit(0);
	}
	else
	{
		perror("fork.");
	}
	return 0;
}
/*
int main()
{
	pid_t pid = fork();
	if(pid>0)
	{
		int status;
		wait(&status);
		printf("Parent id=%d\n",getpid());
	}
	else if(pid == 0)
	{
		printf("Child id=%d\n",getpid());
	}
	else
	{
		perror("fork");
	}

	return 0;
}
*/
