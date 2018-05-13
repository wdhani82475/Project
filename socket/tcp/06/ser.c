#include"../utili.h"
#include<pthread.h>
#define MAX_NUM  5
char buffer[BUFFER];
static int a;
int main()
{
	struct sockaddr_in ser_addr,cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(8080);
	ser_addr.sin_addr.s_addr =inet_addr("127.0.0.1"); 
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
	
	int client_sockConn[MAX_NUM];//集合大小
	int client_conn_num = 0;//连接数
	fd_set set;//集合大小
	int i;
	int max_fd = sockSer;
	while(1)
	{
		FD_ZERO(&set);
		FD_SET(sockSer,&set);
		int i;
		for(i=0;i<MAX_NUM;i++)
		{
			if(client_sockConn[i] != 0)
			{
				FD_SET(client_sockConn[i],&set);
			}
		}
		int ret = select(max_fd+1,&set,NULL,NULL,NULL);
		if(ret == 0)
		{
			printf("timeout\n");
		}
		else if(ret == -1)
		{
			perror("select");
		}
		else
		{
			if(FD_ISSET(sockSer,&set))
			{
				int connfd = accept(sockSer,(struct sockaddr*)&cli_addr,&cli_len);
				if(connfd == -1)
				{
					printf("Cli conn Ser Fail\n");
					continue;
				}
				else
				{	
					a++;
					printf("A Baby Come..\n");
					printf("num = %d\n",a);
					client_conn_num++;
					for(i=0;i<MAX_NUM;i++)
					{
						if(client_sockConn[i] == 0)
						{
							client_sockConn[i] = connfd;
							break;
						}
					}
					if(i>=MAX_NUM)
					{
						printf("Ser over Load\n");
					}
					else
					{
						if(connfd > max_fd)
							max_fd = connfd;
					}

				}

			}
		else
		{
			for(i=0;i<MAX_NUM;i++)
			{
				if(FD_ISSET(client_sockConn[i],&set))
				{
					int recvbyte=recv(client_sockConn[i],buffer,BUFFER,0);
					send(client_sockConn[i],buffer,strlen(buffer)+1,0);
				

				}
			}

		}
	}
	}
	close(sockSer);
	return 0;
}
