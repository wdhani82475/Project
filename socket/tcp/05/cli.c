#include"../utili.h"
#include<pthread.h>
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr =inet_addr(SER_IP); 
	int sockCli = Socket(AF_INET,SOCK_STREAM,0);
	socklen_t cli_len = sizeof(struct sockaddr_in);
	int res = Connect(sockCli,(struct sockaddr*)&ser_addr,cli_len);
	char send_buffer[BUFFER];
	char recv_buffer[BUFFER];
	while(1)
	{
		printf("Cli>");
		scanf("%s",send_buffer);
		send(sockCli,send_buffer,strlen(send_buffer)+1,0);
		recv(sockCli,recv_buffer,BUFFER,0);
		printf("Ser>%s\n",recv_buffer);
	}
	close(sockCli);
	return 0;
}
