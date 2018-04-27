#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
	char *parent_talk[]={"Hello","What time is it now?","I have no time ,byebye",NULL};
	char *child_talk[]={"Hi","No problem","byebye",NULL};
	int fd1[2];
	int fd2[2];
	int res = pipe(fd1);
	if(res == -1)
	{
		printf("Creat Pipe1 Fail\n");
		exit(1);
	}
	res = pipe(fd2);
	if(res == -1)
	{
		printf("Creat Pipe2 Fail.\n");
		exit(1);
	}
	pid_t pid = fork();
	if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);
		int i=0;
		char buffer[256];
		char *parent = parent_talk[i];
		while(parent != NULL)
		{
			write(fd1[1],parent,strlen(parent)+1);
			read(fd2[0],buffer,256);
			printf("From Child >%s\n",buffer);
			i++;
			parent = parent_talk[i];
		}
		close(fd1[1]);
		close(fd2[0]);
	}
	else if(pid == 0)
	{
		close(fd1[1]);
		close(fd2[0]);
		int i= 0;
		char buffer[256];
		char *child = child_talk[i];
		while(child != NULL)
		{
			read(fd1[0],buffer,256);
			printf("From Parent >%s\n",buffer);
			if(i == 1)
			{
				time_t tt;
				time(&tt);
				char buffer[256];
				//printf("%s",ctime(&tt));
				memset(buffer,0,256);
				sprintf(buffer,"%s %s",child,ctime(&tt));
				//printf("buffer=%s\n",buffer);
				write(fd2[1],buffer,strlen(buffer)+1);
			}
			else
			{
				write(fd2[1],child,strlen(child)+1);
			}
			i++;
			child = child_talk[i];
		}

		close(fd1[0]);
		close(fd2[1]);
	}
	else
	{
		perror("fork");
	}
	return 0;
}

/*
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char *msg="Hello Pipe";
	int fd[2];
	int res= pipe(fd);
	pid_t pid = fork();
	if(pid>0)
	{
		close (fd[0]);
		write(fd[1],msg,strlen(msg)+1);
		close (fd[1]);
	}
	else if(pid == 0)
	{
		close (fd[1]);
		//建议
		char buffer[256];
		read(fd[0],buffer,256);
		printf("From Parent Meg %s\n",buffer);
		close (fd[0]);
	}
	else
		perror("fork");
	return 0;
}
*/
