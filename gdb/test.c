#include<stdio.h>
#include<unistd.h>
void dummy_function()
{
	unsigned  char *ptr =0x00;
	*ptr = 0x00;
}

int main()
{
	dummy_function();
	return 0;
}

