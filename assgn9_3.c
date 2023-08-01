#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{
	int ret = 0;	
	ret =  getpriority(PRIO_PROCESS,0);
	
	printf("Priority of the process is: %d\n",ret);
	
	return 0;
}

