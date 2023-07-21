#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    char filename[20];
    int fd = 0;
    char str[12] = "Hello world";
    
    printf("Enter the file name that you want to open : \n");
    scanf("%s",filename);
    
    fd = creat(filename, 0777);
      
    if(fd == -1)
    {
    	printf("Unable to open file.\n");
    	return -1;
    }
    
    write(fd,str,strlen(str));
    
    return 0;
}
    
