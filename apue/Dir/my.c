#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd = open("2.txt",O_CREAT|O_WRONLY,0755);
	if(fd == -1)
		perror("Open");
	close(1);
	fcntl(fd,F_DUPFD,1);
	printf("asdfjkhgfsad");
	return 0;
}
/*
int main()
{
	int fd = open("1.txt",O_CREAT|O_WRONLY,0755);
	if(fd == -1)
	{
		perror("Open");
	}
	close(1);
	int res = fcntl(fd,F_DUPFD,0);
	printf("1123456789");
	return 0;
}
*/
