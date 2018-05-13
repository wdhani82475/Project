#include"../utili.h"
#include<pthread.h>
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(8080);
	ser_addr.sin_addr.s_addr =inet_addr("127.0.0.1"); 
	int sockCli = Socket(AF_INET,SOCK_STREAM,0);
	socklen_t cli_len = sizeof(struct sockaddr_in);
	int res = Connect(sockCli,(struct sockaddr*)&ser_addr,cli_len);
	char send_buffer[BUFFER];
	char recv_buffer[BUFFER];
	while(1)
	{
		printf("Cli>");
		scanf("%s",send_buffer);
		int sendbyte=send(sockCli,send_buffer,strlen(send_buffer)+1,0);
		if(sendbyte <0 )
		{
			printf("Send Data Error\n");
		}
		recv(sockCli,recv_buffer,BUFFER,0);
		printf("From Myself Msg>%s\n",recv_buffer);
	}
	close(sockCli);
	return 0;
}
