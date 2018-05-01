#include"../ipc.h"
#include"uliti.h"
int main(int argc,char *argv[])
{
	key_t msg_key= Ftok(argv[1],atoi(argv[2]));
	printf("msg_key = %x\n",msg_key);
	int msg_id = Msgget(msg_key,IPC_CREAT|0755);
	printf("msg_id =%d\n",msg_id);
	typedef	struct msgbuf
	{
		long mtype;
		char mtext[BUF_SIZE];
	}Msg;
	Msg msg;
	while(1)
	{
		msg.mtype = Ser_Snd_Flag;
		printf("Ser>");
		scanf("%s",msg.mtext);
		msgsnd(msg_id,&msg,strlen(msg.mtext)+1,0);
		msgrcv(msg_id,&msg,BUF_SIZE,Ser_Rev_Flag,0);
		printf("Cli>%s\n",msg.mtext);
	}
	int res= msgctl(msg_id,IPC_RMID,NULL);
	if(res == -1)
	{
		printf("Remove msg fail\n");
	}
	else
		printf("Remove msg success.\n");


	return 0;
}


