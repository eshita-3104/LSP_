#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int ret = 0;
	int cpid = 0;
	int exit_status = 0;
	
	ret = fork();
	
	if(ret == 0 )
	{
		execl("./ChildProcess","NULL",NULL);
	 
	}
	
	else
	{
		printf("PArent is running with PID: %d\n",getpid());
		cpid = wait(&exit_status);
		printf("Child process terminated having pic %d with exit status %d\n",cpid, exit_status);
	}
	
	return 0;
}

