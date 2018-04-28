#ifndef __IPC_H__
#define __IPC_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
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
int Shmget(key_t key,size_t size,int oflag )
{
	int shm_id = shmget(key,size,oflag);
	if(shm_id == -1)
	{
		perror("shm_id");
	}
	return shm_id;
}
void *Shmat(int shmid,const void *shmaddr,int shmflg )
{
	
	void *addr =(void *)shmat(shmid,shmaddr,shmflg);
	if((void*)addr == (void*)-1)
	{
		perror("shmat");
		shmctl(shmid,IPC_RMID,NULL);
		exit(1);
	}
	return addr;
}
int Shmdt(const void *shmaddr)
{
	int ret = shmdt(shmaddr);
	if(ret == -1)
	{
		perror("shmdt");
	}
	return ret;
}
///////////////////////////////////////////////
int Msgget(key_t key,int oflag)
{
	int res = msgget(key,oflag);
	if(res == -1)
	{
		perror("msgget");
	}
	return res;
}
#endif

