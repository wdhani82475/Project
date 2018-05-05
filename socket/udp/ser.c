#include"utili.h"
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr = inet_addr(SER_IP);
	int sockSer = Socket(AF_INET,SOCK_DGRAM,0);
	socklen_t sock_len = sizeof(struct sockaddr);
	int res = Bind(sockSer,(struct sockaddr *)&ser_addr,sock_len);
	char send_buffer[BUFFER_SIZE];
	char recv_buffer[BUFFER_SIZE];
	while(1)
	{
		recvfrom(sockSer,recv_buffer,BUFFER_SIZE,0,( struct sockaddr*)&cli_addr,&sock_len);
		printf("Cli>%s\n",recv_buffer);
		printf("Ser>");
		scanf("%s",send_buffer);
		sendto(sockSer,send_buffer,strlen(send_buffer)+1,0,(const struct sockaddr*)&cli_addr,sock_len);
	}
	return 0;
}
