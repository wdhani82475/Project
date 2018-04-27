#include"../ipc.h"
#include<sys/sem.h>
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s pathname proj_id\n",argv[0]);
	}
	key_t key = Ftok(argv[1],atoi(argv[2]));
	int sem_id = Semget(key,0,0);
	struct sembuf ptr;
	ptr.sem_num = 0;
	ptr.sem_op = -1;
	ptr.sem_flg = 0;
	//struct sembuf ptr = {0,-1,0};
	int res = semop(sem_id,&ptr,1);
	if(res == -1)
		perror("semop");

	return 0;
}
