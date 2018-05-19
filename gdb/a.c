#include<stdio.h>
#include<unistd.h>
int add(int a,int b)
{
	int c = a+b;
	return c;
}

int main()
{
	int a=3;
	int b=5;
	int c=add(a,b);
	printf("c=%d\n",c);
	return 0;
}

