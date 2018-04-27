#ifndef __IPC_H__
#define __IPC_H__
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
//////////////////////
key_t Ftok(char *pathname,int id)
{
	key_t key = ftok(pathname, id);
	if(key == -1)
	{
		perror("key");
		exit(1);
	}
	return key;
}
int Semget(key_t key,int nsems,int oflag)
{
	int sem_id = semget(key,nsems,oflag);
	if(sem_id == -1)
	{
		perror("semget");
	}
	return sem_id;
}
union semun
{
	int val;
	struct semid_ds *buf;
	ushort *array;
};
/////////////////////////////////

#endif

