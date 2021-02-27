/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <time.h>

int main(){

    clock_t c_init;
    clock_t c_final;
    c_init = clock();

    for (int i = 0; i < 1000000; i++){}
    for (int i = 0; i < 1000000; i++){}
    for (int i = 0; i < 1000000; i++){}

    c_final = clock();
    double clock_diff = (double) c_final - c_init;
    printf("Clock Diff: %f\n", clock_diff);

    
    return 0;
}