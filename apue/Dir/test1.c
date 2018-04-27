#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
int main()
{
	char buffer[100];
	memset(buffer,0,100);
    getcwd(buffer,100);
	DIR *ptr=opendir(buffer);
	struct dirent* dir;
	while((dir=readdir(ptr))!= NULL)
	{
		printf("%s   ",dir->d_name);
	}
	printf("\n");
	closedir(ptr);
	return 0;

}
