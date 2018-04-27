#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid>0)
	{
		sleep(2);
		printf("Parent[%d]\n",getpid());
	}
	else if(pid == 0)
	{
	    //sleep(4);	
		printf("My Parent[%d]\n",getppid());
		printf("Child[%d]\n",getpid());
	}
	else
	{
		perror("fork");
	}
	return 0;
}
/*
int main()
{
	pid_t pid;
	pid = fork();
	switch(pid)
	{
	case -1:
		perror("fork");
		break;
	case 0:
		printf("child pid=%d\n",getpid());
	    break;
	default:
		printf("parent pid=%d\n",getpid());
		break;
		sleep(50);
	}
	return 0;
}
*/
