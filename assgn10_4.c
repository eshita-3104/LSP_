#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr) 
{
	printf("Enter the value:");
	scanf("%u",&ptr);
	int i = (int)ptr;	
	pthread_exit(++i);
}
int main()
{
	pthread_t TID; 
	int ret = 0;
	int no = 0;
	int value = 0;	
	ret =  pthread_create(&TID, NULL, ThreadProc, (int *)no);
	
	if(ret !=0)
	{
		printf("unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with TID: %u\n",TID);
	
	pthread_join(TID,&value);
	
	printf("Return value from thread is: %d\n",value);
	printf("end of main thread\n");
	pthread_exit(NULL);
	
	return 0;
}
