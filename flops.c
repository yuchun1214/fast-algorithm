#include <time.h>
#include <stdio.h>
#include <limits.h>

int main(){
    clock_t c1, c2;
    long times = INT_MAX;
    double t;
    double res;
    c1 = clock();
    for(long i = 0; i < times; ++i){
        res *= 0.3; 
    }
    c2 = clock();
    t = (c2 - c1)/(double)CLOCKS_PER_SEC;
    printf("Times usage : %.3f\n", t);
    printf("FLOPS : %g\n", t/(double)times);
}
