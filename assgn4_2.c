#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	char DirName[20];
	int new_dir;
        printf("Enter name of directory : \n");
        scanf("%s",DirName);
	
	new_dir = mkdir(DirName,0777);
	
	if(!new_dir)
	{
		printf("Directory created.\n");
	}
	else
	{
		printf("No directory created");
	}
	return 0;
}
