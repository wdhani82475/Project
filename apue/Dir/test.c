#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char buffer[100];
	memset(buffer,0,100);
	char *res = getcwd(buffer,100);
	char *ret = getwd(buffer);
	printf("res=%s\n ",res);
	printf("buffer=%s\n",buffer);
	return 0;
}

/*
int main(int argc,char *argv[])

{
	if(argc != 2)
		printf("Usage:a.out<pathname>");
	if(access (argv[1],F_OK)<0)
	    printf("access error for %s",argv[1]);
	else
		printf("file ok");
	return 0;
}
*/



