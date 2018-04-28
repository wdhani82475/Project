#include"../../ipc.h"
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
	while(1)
	{
		printf("Cli>");
		scanf("%s",addr);
		printf("Ser>%s\n",addr);
	}
	return 0;
}
