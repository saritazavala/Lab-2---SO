/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(){
    for(int i=0; i < 4; ++i){
        fork();
        printf("Fork %d %d\n", i + 1, getpid());
    }
    return 0;
}
