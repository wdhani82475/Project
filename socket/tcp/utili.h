#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define SER_PORT 9090
#define SER_IP "10.0.2.15"
#define LISTEN_NUM 12 //定义连接请求队列长度
#define BUFFER 256

////////////////////////////////
int Socket(int domain,int type,int protocol)
{
	int sockSer=socket(domain,type,protocol);
	if(sockSer == -1)
	{
		perror("socket");
	}
	return sockSer;
}

int Bind(int socket,const struct sockaddr *address,socklen_t address_len)
{
	int ret = bind(socket,address,address_len);
	if(ret == -1)
	{
		perror("bind");
	}
	return 0;
}
int  Listen(int socket,int backlog)
{
	int res  = listen(socket,backlog);
	if(res == -1)
	{
		perror("listen queue");
	}
	return 0;
}

int Accept(int socket,struct sockaddr *address,socklen_t * address_len)
{
	int connfd = accept(socket,address,address_len);
	if(connfd == -1)
	{
		perror("connfd");
	}
	return connfd;
}
int Connect(int socket,struct sockaddr *addr,socklen_t address)
{
	int res = connect(socket,addr,address);
	if(res == -1)
	{
		printf("Cli Connect Ser Fail\n");
		exit(1);
	}
	else
	{	
		printf("Cli Connect Ser Success.\n");
	}
}
///////////////////////////////
