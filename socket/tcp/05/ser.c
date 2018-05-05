#include"../utili.h"
#include<pthread.h>
//void*  send_msg(void *arg);
//void*  recv_msg(void *arg);


char send_buffer[BUFFER];
char recv_buffer[BUFFER];
void * handle(void *arg)
{
	int fd = *(int *)arg;
	while(1)	
	{
		printf("Ser>");
		scanf("%s",send_buffer);	
		if(!strcmp(send_buffer,"quit"))
		exit(0);
		send(fd,send_buffer,strlen(send_buffer)+1,0);
		recv(fd,recv_buffer,BUFFER,0);
		printf("Cli>%s\n",recv_buffer);
	}
}
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr =inet_addr(SER_IP); 
	int sockSer = Socket(AF_INET,SOCK_STREAM,0);
	//printf("sockSer = %d\n",sockSer);
	socklen_t ser_len =sizeof(struct sockaddr_in);
	int option_val = 1;
	setsockopt(sockSer,SOL_SOCKET,SO_REUSEADDR,&option_val,sizeof(option_val));
	int ret = Bind(sockSer,(struct sockaddr*)&ser_addr,ser_len);
	//printf("ret = %d\n",ret);
	int res = Listen(sockSer,LISTEN_NUM);
	//printf("res = %d\n",res);
	socklen_t cli_len = sizeof(struct sockaddr_in);
	while(1)
	{
		int connfd =Accept(sockSer,(struct sockaddr*)&cli_addr,&cli_len);
		pthread_t tid1,tid2;
		pthread_create(&tid1,NULL,(void*)handle,&connfd);
		pthread_join(tid1,NULL);
	}
		close(sockSer);
	return 0;
}
