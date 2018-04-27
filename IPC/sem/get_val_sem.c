#include"../ipc.h"
#include<sys/sem.h>
int main(int argc,char * argv[])
{
	if(argc != 3)
	{
		printf("Usage %s pathname id .\n",argv[0]);
		return -1;
	}
	key_t key =  Ftok(argv[1],atoi(argv[2]));
	//obtain id
	int sem_id=Semget(key,0,0);
	int res = semctl(sem_id,0,GETVAL);
	if(res == -1)
	{
		perror("GetVal");
	}
	else
		printf("GetVal = %d\n",res);
	return 0;
}
