#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc1(void *ptr) 
{
	printf("Thread 1\n");
	for(int i = 1; i<=500; i++)
	{
		printf("%d\n",i);
	}
	pthread_exit(NULL); 
}

void * ThreadProc2(void *ptr)  
{
	printf("Thread 2\n");
	for(int i = 1; i<=500; i++)
	{
		printf("%d\n",i);
	}
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
	
	printf("End of main thread\n");
	pthread_exit(NULL);
	
	return 0;
}
