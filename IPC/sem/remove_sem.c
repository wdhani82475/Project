#include"../ipc.h"
#include<sys/ipc.h>
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s pathname id.\n",argv[0]);
		return -1;
	}
	key_t key= Ftok(argv[1],atoi(argv[2]));
	int sem_id = Semget(key,0,0);
	int res = semctl(sem_id,0,IPC_RMID);
	if(res == -1)
	{
		perror("ipc_rmid");
	}
	return 0;
}
