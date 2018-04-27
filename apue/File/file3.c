#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
  char buf1[]="abcdefghij";
  char buf2[]="ABCDEFGHIJ";
  int fd = creat("3.txt",0755);
  int ret = open("3.txt",O_WRONLY);
  write(fd,buf1,sizeof(buf1));
  int off=lseek(fd,20,SEEK_SET);
  printf("%d",off);
  write(fd,buf2,sizeof(buf2));
  return 0;
}
