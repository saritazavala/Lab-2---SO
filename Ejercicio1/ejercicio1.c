
/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(){

    fork();
    printf("Fork 1 %d\n", getpid());

    fork();
    printf("Fork 2 %d\n", getpid());

    fork();
    printf("Fork 3 %d\n", getpid());

    fork();
    printf("Fork 4 %d\n", getpid());

    return 0;
}