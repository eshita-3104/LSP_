#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*add)();
    void (*sub)();
    void (*mul)();
    void (*div)();

    ptr = dlopen("./assgn7.so",RTLD_LAZY);
    if(ptr)
    {
    	add = dlsym(ptr,"addition");
        sub = dlsym(ptr,"difference");
        mul = dlsym(ptr,"product");
        div = dlsym(ptr,"divide");
    }
    
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    
    if((add == NULL) || (sub==NULL) || (mul==NULL) || (div==NULL))
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    add();
    sub();
    mul();
    div();
    return 0;
}


// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o

