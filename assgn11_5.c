#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc1(void *ptr) 
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
	pthread_exit(NULL); //kills the thread
}

void * ThreadProc2(void *ptr) 
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
	pthread_exit(NULL); 
}


int main()
{
	pthread_t TID1, TID2; 
	int ret1 = 0, ret2 = 0;	
	ret1 =  pthread_create(&TID1, NULL, ThreadProc1, NULL);
	
	if(ret1 !=0)
	{
		printf("unable to create thread\n");
		return -1;
	}
	
	printf("Thread1 is created with TID: %u\n",TID1);
	
	
	ret2 =  pthread_create(&TID2, NULL, ThreadProc2, NULL);
	
	if(ret2 !=0)
	{
		printf("unable to create thread\n");
		return -1;
	}
	
	printf("Thread2 is created with TID: %u\n",TID2);
	
	pthread_join(TID1,NULL);
	pthread_join(TID2, NULL);
	pthread_exit(NULL);
	
	return 0;
}
