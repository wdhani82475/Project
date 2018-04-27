#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
  int fd = creat("1.txt",O_WRONLY);
  if(fd == -1)
	printf("Creat File Fail.\n");
  close(fd); 
  return 0;
}
