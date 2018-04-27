#include"../ipc.h"
#include<sys/sem.h>
int main(int argc,char *argv[])
{
	// ./creat pathname id
	if(argc != 4)
	{
		printf("Usage %s pathname id nsems.\n",argv[0]);
	}
	key_t key = Ftok(argv[1],atoi(argv[2]));
	printf("key = %x\n",key);
	int sem_id = Semget(key,1,IPC_CREAT|IPC_EXCL|0755);
	printf("sem_id = %d\n",sem_id);
	union semun org;
	org.val=atoi(argv[3]);
	int res =  semctl(sem_id,0,SETVAL,org);
	if(res == -1)
	{
		perror("Init");
	}
	return 0;
}
