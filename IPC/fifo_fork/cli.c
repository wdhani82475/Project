#include"utili.h"
int main()
{
	if(read_fd == -1)
	{
		perror("read_fd");
		exit(1);
	}
	if(access(read_fifo,F_OK) !=0)	
	{
		int res = mkfifo(read_fifo,O_CREAT|O_EXCL|0755);
		if(res == -1)
		{
			perror("read_fifo");
			close(read_fd);
			exit(1);
		}
	}
	int write_fd = open(read_fifo,O_WRONLY);
	if(write_fd == -1)
	{
		perror("write_fd");
		exit(1);
	}
	pid_t pid = fork();
	if(pid==0)
	{
		//write
		write_msg(write_fd);
	}
	else if(pid>0)
	{
		pid = fork();
		if(pid == 0)
		{
			//read
			read_msg(read_fd);
		}
		else if(pid >0)
		{
			int status;
			wait(&status);
		}
		else
		{
			perror("fork");
		}
	}
	else
	{
		perror("fork");
	}


	return 0;
}
void read_msg(int fd)
{
	char buf[256];
	while(1)
	{
		read(fd,buf,256);
		printf("Ser>%s\n",buf);
	}

}
void write_msg(int fd)
{
	while(1)
	{

		printf("Cli>");
		char buf[256];
		scanf("%s",buf);
		if(!strcmp(buf,"quit"))
			break;
		write(fd,buf,strlen(buf)+1);
	}
}
