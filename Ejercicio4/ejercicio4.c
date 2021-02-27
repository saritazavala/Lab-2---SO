/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <unistd.h>

int main(){
    int p_1 = fork();
    if(p_1 == 0){
        printf("I'm a child! \n");
    }else{
        for(;;);
    }

    return 0;
}