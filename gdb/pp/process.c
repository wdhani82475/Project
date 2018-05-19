#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid = fork();
	int status;
	if(pid>0)
	{
		wait(&status);
		printf("parent pid =%d\n",getpid());
	}
	else if(pid == 0)
	{
		printf("child pid =%d\n",getpid());
	}
	else
	{
		perror("fork");
	}

	return 0;
}
