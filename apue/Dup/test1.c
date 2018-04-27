#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
  int  fd = open("yourfile.txt",O_WRONLY|O_CREAT,0755);
  //1 == STDOUT_FILENO
  printf("fd = %d\n",fd);
  int fd1=dup2(fd,1);
  printf("fd1 = %d\n",fd1);
  printf("Dup To Fun()");
  return 0;
}
