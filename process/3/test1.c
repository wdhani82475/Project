#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
pid_t g_pid;
int main()
{
	pid_t pid=fork();
	if(pid>0)
	{
		g_pid = pid;
		pid=fork();
		if(pid>0)
		{
			sleep(1);
			printf("This is 0 process[%d]\n",getpid());
			int status;
			//pid_t id=wait(&status);
			 pid_t id = waitpid(g_pid,&status,WUNTRACED);
			printf("Wait Process =%d\n",id);
			if(WIFEXITED(status))
			{
				printf("Child is OK finish.\n");
			}
			else
				printf("Child is error finish.\n");
		}
		else if(pid==0)
		{
			sleep(1);
			printf("This is 1 process[%d]\n",getpid());
		}
	}
	//指定等待 子进程 id
	else if(pid == 0)
	{
		pid=fork();
		if(pid>0)
		{

			//sleep(1);
			sleep(3);
			printf("This is 2 process[%d]\n",getpid());
		}
		else if(pid == 0)
		{
			printf("This is 3 process[%d]\n",getpid());
		}
	}
	else
		perror("fork");
}
