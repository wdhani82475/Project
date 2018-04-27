#include<stdio.h>
#include<unistd.h>
int main()
{
	//execl("/bin/ls","ls",NULL);
	char *envp[]={"ls",NULL};
	//execvp("ls",envp);
	execv("/bin/ls",envp);
	return 0;
}

