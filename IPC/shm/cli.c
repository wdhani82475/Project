#include"../ipc.h"
#include<sys/sem.h>
int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("Usage:shm < %s pathname proj_id>",argv[0]);
		exit(1);
	}
	key_t  shm_key = Ftok(argv[1],atoi(argv[2]));
	int shm_id = Shmget(shm_key,0,0);
	char *addr = Shmat(shm_id,NULL,0);
	///////////////////////////////////
	int sem_id = Semget(shm_id,0,0);
	union  semun info;
	info.val = 0;
	semctl(sem_id,0,SETVAL,&info);
	semctl(sem_id,1,SETVAL,&info);

	struct sembuf p={0,-1,0};
	struct sembuf v={1,1,0};
	///////////////////////////////////
	while(1)
	{
		semop(sem_id,&p,1);
		printf("Ser> %s\n",addr);

		semop(sem_id,&v,1);
		printf("Cli>");
		scanf("%s",addr);
	}
	return 0;
}
