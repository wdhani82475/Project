#include"../utili.h"

int send_msg(int fd);
int recv_msg(int fd);
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr =inet_addr(SER_IP); 
	int sockCli= Socket(AF_INET,SOCK_STREAM,0);
	int option_val = 1;
	socklen_t ser_len =sizeof(struct sockaddr_in);
 	int res =Connect(sockCli,( struct sockaddr*)&ser_addr,ser_len);
	pid_t pid;
	pid = fork();
	if(pid>0)
	{	
		pid = fork();
		if(pid == 0)
		{
			send_msg(sockCli);
		}

		else if(pid >0)
		{
			int status;
			wait(&status);
		}
	}
	else if(pid == 0)
	{
		 recv_msg(sockCli);
	}	
	close(sockCli);
	return 0;
}
	char send_buffer[BUFFER];
	char recv_buffer[BUFFER];
	send_msg(int fd)
	 {
		 while(1)
		 {
			printf("Cli>");
		 	scanf("%s",send_buffer);
			if(!strcmp(send_buffer,"quit"))
				break;
		 	send(fd,send_buffer,strlen(send_buffer)+1,0);
		 }
		return 0;
	 }
	recv_msg(int fd)
	{
		while(1)
		{
			recv(fd,recv_buffer,BUFFER,0);
			printf("Ser>%s\n",recv_buffer);
		}
		return 0;
	}
	
