#include<time.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	time_t tt;
	time(&tt);
	printf("%s",ctime(&tt));
}
