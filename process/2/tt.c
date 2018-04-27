#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Parent id=%d,Child id=%d\n",getppid(),getpid());
	return 0;
}
