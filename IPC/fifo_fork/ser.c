#include"utili.h"
int main()
{
	//创建管道
	if(access(write_fifo,F_OK) != 0)
	{
		int res = mkfifo(write_fifo,O_CREAT|O_EXCL|0755);
		if(res == -1)
		{
			perror(" fifo");
			exit(1);
		}
	}
	//打开管道
	int write_fd = open(write_fifo,O_WRONLY);
	if(write_fd == -1)
	{
		perror("write_fd");
		exit(1);
	}
	int read_fd;
	while((read_fd=open(read_fifo,O_RDONLY))== -1)
	{
		printf("Client not start up.\n");
		sleep(1);
	}
	pid_t pid = fork();
	if(pid == 0)
	{
		//read
		read_msg(read_fd);
	}
	else if(pid > 0)
	{
		pid = fork();
		if(pid == 0)
		{	
			//write
			write_msg(write_fd);
		}
		else if(pid >0)
		{	
			int status;
			wait(&status);
			close(write_fd);
			close(read_fd);
		}
		else
			perror("fork");
	}
	else
	{
		perror("fork");
	}
	return 0;
}
void write_msg(int fd)
{
	char buf[256];
	while(1)
	{

		printf("Ser>");
		scanf("%s",buf);
		if(!strcmp(buf,"quit"))
		{
			break;
		}
		write(fd,buf,strlen(buf)+1);
	}
}
	void read_msg(int fd)
	{
		char buf[256];
		while(1)
		{
			read(fd,buf,256);
			printf("Cli>%s\n",buf);
		}
	}
