#include"../utili.h"
#include<pthread.h>

char send_buffer[BUFFER];
char recv_buffer[BUFFER];
send_msg(void *arg)
{
	int fd = *(int*)arg;
	while(1)
	{
		
		printf("CLi>");
		scanf("%s",send_buffer);	
		if(!strcmp(send_buffer,"quit"))
			exit(0);
		send(fd,send_buffer,strlen(send_buffer)+1,0);

	}
	pthread_exit(NULL);
}
recv_msg(void *arg)
{
	int fd = *(int*) arg;
	while(1)
	{
		recv(fd,recv_buffer,BUFFER,0);
		printf(	"Ser>%s\n",recv_buffer);
	}
	pthread_exit(NULL);
}

int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr =inet_addr(SER_IP); 
	int sockCli = Socket(AF_INET,SOCK_STREAM,0);
	socklen_t cli_len = sizeof(struct sockaddr_in);
	int res = Connect(sockCli,(struct sockaddr*)&ser_addr,cli_len);
		pthread_t tid1,tid2;
		pthread_create(&tid1,NULL,(void*)recv_msg,&sockCli);
		sleep(1);
		pthread_create(&tid2,NULL,(void*)send_msg,&sockCli);
		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
		close(sockCli);
	return 0;
}
