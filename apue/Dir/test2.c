#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	struct stat buf;
	if(argc != 2)
	{
		printf("Usage: my_stat <filename>\n");
		exit(0);
	}
	if(stat(argv[1],&buf) == -1)
	{
		perror("stat:");
		exit(1);
	}
	printf("device id %d\n",buf.st_dev);
	return 0;
}

