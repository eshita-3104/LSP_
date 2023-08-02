//process 1
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char buffer[512];
	int icnt = 0, iret = 0, i = 0, fd = 0;
	
	fd = open("demo.txt",O_RDONLY);
	
	while((iret = read(fd, buffer,sizeof(buffer)))!=0)
	{
		for(i=0;i<iret;i++)
		{
			if ((buffer[i]>='a')&&(buffer[i]<='z'))
			{
				icnt++;
			}
		}
	}
	
	printf("Number of small characters is: %d\n",icnt);
	
	close(fd);
	return 0;
}

____________________________________________________________________________________________________________

//process 2

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char buffer[512];
	int icnt = 0, iret = 0, i = 0, fd = 0;
	
	fd = open("demo.txt",O_RDONLY);
	
	while((iret = read(fd, buffer,sizeof(buffer)))!=0)
	{
		for(i=0;i<iret;i++)
		{
			if ((buffer[i]>='A')&&(buffer[i]<='Z'))
			{
				icnt++;
			}
		}
	}
	
	printf("Number of capital characters is: %d\n",icnt);
	
	close(fd);
	return 0;
}

________________________________________________________________________________________________________

//dmonstrarion of multiprocessing 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int ret1 = 0 , ret2 = 0;
	
	ret1 = fork();
	if(ret1 == 0)
	{
		execl("./process1","NULL",NULL);	
	}
	
	ret2 = fork();
	if(ret2 == 0)
	{
		execl("./process2","NULL",NULL);	
	}
	
	
	return 0;
}
