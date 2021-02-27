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

    pid_t pid_1;
    pid_t pid_2;
    pid_t pid_3;

    clock_t c_init;
    clock_t c_final;

    c_init = clock();
    pid_1 = fork(); 
    
    if(pid_1 == 0) {
        
        pid_2 = fork();

        if(pid_2 == 0) {    
            pid_3 = fork();
         
            if(pid_3 == 0) {
                for (int i = 0; i < 1000000; i++)
                    printf("Indice: %d\n", i);
            }else 
            {
                for (int i = 0; i < 1000000; i++)
                    printf("Indice: %d\n", i);

                wait(NULL);
            }
        }else 
        {
            for (int i = 0; i < 1000000; i++)
                printf("Indice: %d\n", i);

            wait(NULL);
        }

    }else {
        c_final = clock();
        wait(NULL);
      
        double clock_diff = (double) c_final - c_init;
        printf("Clock Diff: %f\n", clock_diff);
    }

    return 0;
}