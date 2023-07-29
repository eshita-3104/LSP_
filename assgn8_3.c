#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{	
	int ret = 0;
	int cpid = 0;
	int exit_status = 0;
	for(int i = 1; i<=3; i++)
	{
		ret = fork();
		if(ret==0)
		{
			printf("Process %d is created with pid: %d. : parent pid is: %d\n",i,getpid(),getppid());
			exit(0);
		}
			
	}
	for(int i = 1; i<=3; i++)
	{
		cpid = wait(&exit_status);
	}
	
	return 0;
}
