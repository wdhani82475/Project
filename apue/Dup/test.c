#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
  int fd = open("myfile.txt",O_WRONLY|O_CREAT,0755);
  //1 == STDOUT_FIELNO
  close(1);
  //重定向了输出方向
  int fd1=dup(fd);
  printf("Hello Dup fun()");
  return 0;
}
