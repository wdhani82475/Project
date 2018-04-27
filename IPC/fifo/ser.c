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
	//打开管道i
	printf("12345678\n");
	int write_fd = open(write_fifo,O_WRONLY);
	if(write_fd == -1)
	{
		perror("write_fd");
		exit(1);
	}
	int read_fd;
	printf("222222222222222222\n");
	while((read_fd=open(read_fifo,O_RDONLY))== -1)
	{
		printf("Client not start up.\n");
		sleep(1);
	}
	char send_buf[256];
	char recv_buf[256];
	while(1)
	{
		printf("Ser>");
		scanf("%s",send_buf);
		write(write_fd,send_buf,strlen(send_buf)+1);
		printf("Cli>");
		read(read_fd,recv_buf,256);
		printf("%s\n",recv_buf);
	}
	close(write_fd);
	colse(read_fd);
	return 0;
}
