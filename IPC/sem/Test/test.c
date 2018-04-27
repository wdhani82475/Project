#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
int main()
{
	key_t key = ftok("../yourfile",0xffee);
	if(key == -1)
	{
		perror("Ftok key");
		exit(1);
	}
	else
		printf("key =%x\n",key);

	int sem_id = semget(key,1,IPC_CREAT|0755);
	if(sem_id == -1)
	{
		perror("IPC creat");
		exit(1);
	}
	else
		printf("sem_id = %d\n",sem_id);
	//set init val
	union semun
	{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
		struct seminfo *__buf;
	};
	union semun info;
	info.val = 3;
	int re=semctl(sem_id,0,SETVAL,info );
	if(re == -1)
	{
		perror("set val");
	}
	else
		printf("init val success.\n");
	//get val
	int res = semctl(sem_id,0,GETVAL);
	if(res == -1)
	{
		perror("getval ");
	}
	else
		printf("val =%d\n",res);
	//op sem
	struct sembuf op;
	op.sem_num = 0;
	op.sem_op = -1;
	op.sem_flg = 0;
	int value;
	value= semop(sem_id,&op,1);
	if(value == -1)
	{
		perror("op error.");
	}
	else
		printf(" semop success.\n");


	//get val
	 res = semctl(sem_id,0,GETVAL);
	if(res == -1)
	{
		perror("getval ");
	}
	else
		printf("val =%d\n",res);
	//ipsrm 
	 res = semctl(sem_id,0,IPC_RMID);
	if(res == -1)
	{
		printf("Remove sem fail\n");
	}
	else
		printf("Remove sem success\n");
	return 0;
}


