#include"../ipc.h"
#include<sys/sem.h>
int main(int argc,char * argv[])
{
	if(argc != 4)
	{
		printf("Usage %s pathname id SETVAL.\n",argv[0]);
		return -1;
	}
	key_t key =  Ftok(argv[1],atoi(argv[2]));
	//obtain id
	int sem_id=Semget(key,0,0);
	union semun org;
	org.val = atoi(argv[3]);
	int res = semctl(sem_id,0,SETVAL,org);
	if(res == -1)
	{
		perror("SetVal");
	}
	else
		printf("SetVal Success.\n");
	return 0;
}
