#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define SER_PORT 8080
#define SER_IP "10.0.2.15"
#define BUFFER_SIZE 256

/////////////////////////////
int Socket(int domain,int type,int protocol)
{
	int sockSer = socket(domain,type,protocol);
	if(sockSer == -1)
	{
		perror("sockSer");
	}
	return sockSer;
}
int Bind(int socket ,const struct sockaddr *address,socklen_t  address_len)
{
	int res = bind(socket,address,address_len);
	if(res == -1)
	{
		perror("bind");
	}
	else
	{
		printf("12345678\n");
	}
		return 0;
}


//////////////////////////////
