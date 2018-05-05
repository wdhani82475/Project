#include"../utili.h"

int send_msg(int fd);
int recv_msg(int fd);
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr =inet_addr(SER_IP); 
	int sockSer = Socket(AF_INET,SOCK_STREAM,0);
	//printf("sockSer = %d\n",sockSer);
	int option_val = 1;
	int ret =setsockopt(sockSer,SOL_SOCKET,SO_REUSEADDR,&option_val,sizeof(option_val));
	if(ret == -1)
	{
		printf("setsockopt error");
	}
	socklen_t ser_len =sizeof(struct sockaddr_in);
	ret = Bind(sockSer,(struct sockaddr*)&ser_addr,ser_len);
	//printf("ret = %d\n",ret);
	int res = Listen(sockSer,LISTEN_NUM);
	//printf("res = %d\n",res);
	socklen_t cli_len = sizeof(struct sockaddr_in);
	int connfd =Accept(sockSer,(struct sockaddr*)&cli_addr,&cli_len);
	pid_t pid;
	pid = fork();
	if(pid>0)
	{	
		pid = fork();
		if(pid == 0)
		{
			send_msg(connfd);
		}

		else if(pid >0)
		{
			int status;
			wait(&status);
		}
	}
	else if(pid == 0)
	{
		recv_msg(connfd);
	}	
	close(sockSer);
	return 0;
}
char send_buffer[BUFFER];
char recv_buffer[BUFFER];
send_msg(int fd)
{
	while(1)
	{
		printf("Ser>");
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
		printf("Cli>%s\n",recv_buffer);
	}
	return 0;
}

