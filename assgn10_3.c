#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

 
void * ThreadProc(void *ptr) 
{
	printf("Value received from the main thread is: %d\n",(int)ptr);	
}
int main()
{
	pthread_t TID; 
	int ret = 0;
	int no = 11;	
	ret =  pthread_create(&TID, NULL, ThreadProc, (int *)no);
	
	if(ret !=0)
	{
		printf("unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with TID: %u\n",TID);
	
	pthread_join(TID,NULL);
	printf("end of main thread\n");
	pthread_exit(NULL);
	
	return 0;
}

