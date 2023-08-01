
//child
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("This is the child process...\n");
	return 0;
}

______________________________________________________________________________________________________________________

//parent process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret = 0;
	int cpid = 0;
	int exit_status = 0;
	
	ret = fork();
	
	if(ret == 0)
	{
		execl("./child","NULL",NULL);
	}
	else
	{
		printf("This is the parent process...\n");
		cpid = wait(&exit_status);
	}
	
	return 0;
}

_____________________________________________________________________________________________________________________________

//grandparent process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret2 = 0;
	int cpid1 = 0, exit_stat = 0;
	
	ret2 = fork();
	
	if(ret2 == 0)
	{
		execl("./parent", "NULL", NULL);
	}
	else
	{
		printf("This is the grandparent process...\n");
		cpid1 = wait(&exit_stat);
	}
	
	return 0;
}
