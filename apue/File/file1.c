#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
  const char buffer[]="Hello World";
  int len = sizeof(buffer)+1;
  int fd = open("2.txt",O_WRONLY|O_CREAT,0755);
  if(fd == -1)
	printf("Open File Fail.\n");
  int res = write(fd,buffer,len);
 if(res == -1)
	printf("Write Fail Fail.\n");
  return 0;
}
