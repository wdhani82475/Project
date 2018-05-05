#include"../utili.h"


int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr =inet_addr(SER_IP); 
	int sockSer = Socket(AF_INET,SOCK_STREAM,0);
//	printf("sockSer = %d\n",sockSer);
	socklen_t ser_len =sizeof(struct sockaddr_in);
	int ret = Bind(sockSer,(struct sockaddr*)&ser_addr,ser_len);
//	printf("ret = %d\n",ret);
	int res = Listen(sockSer,LISTEN_NUM);
//	printf("res = %d\n",res);
	socklen_t cli_len = sizeof(struct sockaddr_in);
	char send_buffer[BUFFER];
	char recv_buffer[BUFFER];
	while(1)
	{
		int connfd;
 	   connfd =Accept(sockSer,(struct sockaddr*)&cli_addr,&cli_len);
		recv(connfd,recv_buffer,BUFFER,0);
		printf("Cli>%s\n",recv_buffer);
		printf("Ser>");
		scanf("%s",send_buffer);
		if(!strcmp(send_buffer,"quit"))
		{
			break;
		}
		send(connfd,send_buffer,strlen(send_buffer)+1,0);
	}
	close(sockSer);
	return 0;
}
