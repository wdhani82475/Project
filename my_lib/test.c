#include<stdio.h>
#include<dlfcn.h>
int add(int ,int );
int main()
{
	int sum = add(2,3);
	printf("sum = %d\n",sum);
}

