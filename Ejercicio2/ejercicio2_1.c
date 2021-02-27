/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid_1, pid_2, pid_3;
    clock_t c_1, c_2;

    c_1 = clock();
    pid_1 = fork(); 

    if(pid_1 == 0) {

        pid_2 = fork();
        
        if(pid_2 == 0) {    

            pid_3 = fork();

            if(pid_3 == 0) {
                for (int i = 0; i < 1000000; i++);
            }else
            {
                for (int i = 0; i < 1000000; i++);
                wait(NULL);
            }
        }else
        {
            for (int i = 0; i < 1000000; i++);
            wait(NULL);
        }

    }else{
        wait(NULL);
        c_2 = clock();
        printf("Clock Diffe: %f\n", (double) c_2 - c_1);
    }
    
    return 0;
}