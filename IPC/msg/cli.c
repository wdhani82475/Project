#include"../ipc.h"
#include"uliti.h"
int main(int argc,char *argv[])
{
	key_t msg_key = Ftok(argv[1],atoi(argv[2]));
	int msg_id = Msgget(msg_key,0);
	typedef struct msgbuf
	{
		long mtype;
	   	char mtext[BUF_SIZE];
	}Msg;
	Msg msg;
	while(1)
	{
		msgrcv(msg_id,&msg,BUF_SIZE,Cli_Rev_Flag,0);
		printf("Ser>%s\n",msg.mtext);
		printf("Cli>");
	    msg.mtype = Cli_Snd_Flag;
		scanf("%s",msg.mtext);
		msgsnd(msg_id,&msg,strlen(msg.mtext)+1,0);
	}
	return 0;
}


