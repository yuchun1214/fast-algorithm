#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define IS_ODD(num) ((num) & 0x1)
#define IS_EVEN(num) (!IS_ODD(num))

#define _min(u, v) ((u > v) ? v : u)


/**
 * Use Stein's algorithm to implement the function of finding 
 * greatest common divisor.
 * The algorithm is described below : 
 *  1. gcd(0, v) or gcd(u, 0) return the non-zero value
 *  2. gcd(2u, 2v) = 2 gcd(u, v)
 *  3. gcd(2u, v) = gcd(u, v) if v is odd
 *  4. gcd(u, v) = gcd(|u-v|, min(u, v))
 * Ref : https://en.wikipedia.org/wiki/Binary_GCD_algorithm
 */
unsigned long  gcd64(unsigned long u, unsigned long v){
    unsigned long min_value;
    unsigned long diff;
    unsigned long r = 1;
    while(u && v){
        while(IS_EVEN(u) && IS_EVEN(v)) (u >>= 1 , v >>= 1), r <<= 1;
        while(IS_EVEN(v)) v >>= 1;
        while(IS_EVEN(u)) u >>= 1;
        (u > v) ? (diff=u-v,min_value=v) : (diff=v-u, min_value=u);
        u = diff;
        v = min_value;
    }
    return r * ((u) ? u : v);
}

void swap(unsigned long *u, unsigned long *v){
    unsigned temp;
    temp = *u;
    *u = *v;
    *v = temp;
}


int main(int argc, const char *argv[]){
    if(argc < 3){
        printf("Usage : ./gcd [u] [v]");
        exit(EXIT_FAILURE);
    }
    unsigned long u = atoll(argv[1]);
    unsigned long v = atoll(argv[2]);
    clock_t c1, c2;
    double t1;
    c1 = clock();
    unsigned long gcd = gcd64(u, v);
    c2 = clock();
    t1 = (c2 - c1)/(double)CLOCKS_PER_SEC;

 
    printf("gcd between (%lu, %lu) is %lu, time usage : %g(sec)\n",u, v, gcd, t1);
}
