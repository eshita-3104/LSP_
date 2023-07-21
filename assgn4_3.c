#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>


int main(int argc, char* argv[])
{
	int fd1=0, fd2=0, ret=0, icnt=0;
	
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_RDONLY);
	struct stat sobj1, sobj2;
	char buffer1[1024];
	char buffer2[1024];
	if(fd1==-1 || fd2==-1)
	{
		printf("unable to open the file");
		return -1;
	}
	
	fstat(fd1,&sobj1);
	fstat(fd2,&sobj2);
	
	if(sobj1.st_size != sobj2.st_size)
	{
		printf("Files are different");
		return -1;
	}
	
	while(ret = read(fd1,buffer1,sizeof(buffer1)))!=0)
	{
		printf("iteration no: %d",icnt);
		icnt++
		ret = read(fd2,buffer2,sizeof(buffer2));
		if(memcmp(buffer1,buffer2,ret)!=0)
		{
			break;
		}
	}
	
	if(ret==0)
	{
		printf("both files are identical");
	}
	else
	{
		printf("Files are different");
	}
	
	close(fd1);
	close(fd2);
	
	return 0;	
}


