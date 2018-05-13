
#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid = fork();
	int status;
	if(pid>0)
	{
		printf("parent id = %d\n",getpid());
		wait(&status);
	}
	else if(pid == 0)
	{
		printf("child id =%d\n",getpid());
	}
	else
	{
		perror("fork");
	}
	return 0;
}
