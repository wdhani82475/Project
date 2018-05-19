#include<stdio.h>
#include<unistd.h>
int c ;
void fun()
{
	 c = 3;
}
int main()
{
	int a=3;
	int b=5;
	 c = a+b;
	printf("a+b=%d\n",c);
	fun();
	printf("a+b=%d\n",c);
	return 0;
}

