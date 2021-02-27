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
        for (int i = 0; i < 3000000; i++){
            printf("Indices: %d\n", i);
        }
        
    }else
    {
        for(;;);
    }

    return 0;
}