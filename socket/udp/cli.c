#include"utili.h"
int main()
{
	struct sockaddr_in ser_addr, cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr = inet_addr(SER_IP);
	int sock_cli = Socket(AF_INET,SOCK_DGRAM,0);
	char send_buffer[BUFFER_SIZE];
	char recv_buffer[BUFFER_SIZE];
	socklen_t sock_len = sizeof(struct sockaddr);
	while(1)
	{
		printf("Cli>");
		scanf("%s",send_buffer);
		sendto(sock_cli,send_buffer,strlen(send_buffer)+1,0,(const struct sockaddr*)&ser_addr,sock_len);
		recvfrom(sock_cli,recv_buffer,BUFFER_SIZE,0,(struct sockaddr *)&ser_addr,&sock_len);
		printf("Ser>%s\n",recv_buffer);
	}
	return 0;
}
