#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

extern char **environ;
int main()
{
	char **env = environ;
	
	printf("Environment of the running process is: \n");
	
	for(;*env != NULL; env++)
	{
		printf("%s \n",*env);
	}
	
	return 0;
	
	
}

