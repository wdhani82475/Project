#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid = vfork();
	if(pid >0)
	{
		//printf("Parent Process.\n");
	}
	 else if(pid ==0)
	{
		printf("Parent id=%d,Child id=%d\n",getppid(),getpid());
		execl("tt","tt",NULL);
		printf("===============");
	}
	else
	{
		perror("vfork");
	}

	return 0;
}
