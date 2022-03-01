#include <stdio.h>
#include <math.h>

#define check_bit(num, i) ((unsigned long long)(num) & 1<<(i)) 

int main(){
    double num = 12; 
    for(int i = 63; i >= 0; --i){
        printf("%llu", check_bit(num, i) ? 1 : 0);
        if((i & 3l) == 0) printf(" ");
    } 
}
