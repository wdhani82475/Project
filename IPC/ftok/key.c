#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
int main()
{
	key_t key = ftok("myfile",0xff);
	if(key == -1)
	{
		perror("Ftok key");
		exit(1);
	}
	else
	{
		printf("key = %x\n",key);
	}

 	key = ftok("yourfile",0xfe);
	if(key == -1)
	{
		perror("Ftok key1");
		exit(1);
	}
	else
		printf("key1 = %x\n",key);
	return 0;
}


