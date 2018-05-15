#include<stdio.h>
#include"add.h"
#include"sub.h"
int main()
{
	int a, b;
	a = add(1,2);
	b = sub(10,5);
	printf("a = %d,b = %d\n",a,b);
	return 0;
}

