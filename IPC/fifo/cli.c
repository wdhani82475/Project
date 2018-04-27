#include"utili.h"
void write_msg(int fd);
void read_msg(int fd);
int main()
{
	printf("rdrdrdrdrdrdrdrdrrd\n");
	int read_fd;
	read_fd = open(write_fifo,O_RDONLY);
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
	if(pid == 0)
	{
		//write
		write_msg(write_fd);
	}
	else if(pid >0)
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
			perro("fork");
		}

	}
	else
	{
		perro("fork");
	}
	return 0;
}

