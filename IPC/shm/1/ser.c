#include"../ipc.h"
int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("Usage:shm < %s pathname proj_id>",argv[0]);
	exit(1);
	}
	key_t  shm_key = Ftok(argv[1],atoi(argv[2]));
	printf("shm_key = %x\n",shm_key);
	int shm_id = Shmget(shm_key,1024*1024,IPC_CREAT|IPC_EXCL|0755);
	printf("shm_id=%x\n",shm_id);
	
	char *addr =(char*)Shmat(shm_id,NULL,0);	
	while(1)
	{
		printf("Ser>");
		scanf("%s",addr);
		printf("Cli>%s\n",addr);
	}
	int res = Shmdt(addr); 
	struct shmid_ds buff;
	 res = shmctl(shm_id,IPC_RMID,&buff);
	if(res == -1)
	{
		perror("remove_shm");
	}
	printf("Remove shm Success.\n");
	



	return 0;
}
