#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{
	int ret = 0;	
	ret =  nice(0);
	
	printf("Current Priority of the process is: %d\n",ret);
	
	ret = nice(5);
	
	printf("Updated priority of the currrent process is: %d\n",ret);

	return 0;
	
	
}

