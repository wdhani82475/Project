#include<stdio.h>
#include<fcntl.h>
int main()
{
  int fd = open("1.txt",O_RDONLY|O_CREAT,0755);
  //int fd = open("1.txt",O_RDONLY);
  if(fd == -1)
	printf("Create File Fail.\n");
  char buffer[128];
  int ret = read(fd,buffer,128);
  if(ret == -1)
	printf("Read File Fail.\n");
  printf("%s",buffer);  
  close(fd);
  return 0;
}
