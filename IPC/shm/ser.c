#include"../ipc.h"
#include<sys/sem.h>
#include<sys/shm.h>
int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("Usage:shm < %s pathname proj_id>",argv[0]);
	exit(1);
	}
	key_t  shm_key = Ftok(argv[1],atoi(argv[2]));
	int shm_id = Shmget(shm_key,1024*1024,IPC_CREAT|IPC_EXCL|0755);
	char *addr =(char*)Shmat(shm_id,NULL,0);
	////////////////////////////////////////////
	int sem_id = Semget(shm_key,2,IPC_CREAT|0755);
	//init val
	union semun info;
	info.val = 0;
	semctl(sem_id,0,SETVAL,info);
	semctl(sem_id,1,SETVAL,info);
	struct sembuf v={0,1,0};
	struct sembuf p={1,-1,0};
	///////////////////////////////////////////
	while(1)
	{
		printf("Ser>");
		scanf("%s",addr);
		semop(sem_id,&v,1);

		semop(sem_id,&p,1);
		printf("Cli>%s\n",addr);
	}
	int res = Shmdt(addr); 
	semctl(shm_id,0,IPC_RMID);
	semctl(shm_id,1,IPC_RMID);
	 res = shmctl(shm_id,IPC_RMID,NULL);
	if(res == -1)
	{
		perror("remove_shm");
	}
	printf("Remove shm Success.\n");
return 0;
}
