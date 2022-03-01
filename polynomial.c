#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define rand_range(lower, upper) (rand() % ((upper) - (lower)) + (lower))

/* get_function_value1() - get the value of polynomial by given the input
 * 
 * comuting the value of polynomial directly using pow() function
 */
double get_function_value1(int *polynomial, int degree, int input){
    double sum = 0.0;
    for(int i = 0; i <= degree; ++i){
        sum += pow(input, i) * polynomial[i];
    }
    return sum;
}

/* get_function_value2() - get the value of polynomial by given the input
 * 
 * In this function I perform Horner's method which is better than 
 * comuting the value of polynomial directly using pow() function
 */
double get_function_value2(int *polynomial, int degree, int input){
    double result;
    result = polynomial[degree] * input;
    for(int i = degree - 1; i > 0; --i){
        result += polynomial[i];
        result *= input;
    } 
    result += polynomial[0];
    return result;
}

int main(int argc, const char *argv[]){
    if(argc < 3){
        printf("Usage : ./polynomial [degree_of_function] [value_of_x]\n");
        exit(EXIT_FAILURE);
    }
    int degree = atoi(argv[1]);
    int input = atoi(argv[2]);

    int *polynomial = (int*)malloc(sizeof(int)*(degree+1));
    memset(polynomial, 0, sizeof(int)*degree+1);
    

    for(int i = 0; i <= degree; ++i){
        polynomial[i] = rand_range(-10, 10);
    }
    /* 
    printf("The polynomial is : \n");
    for(int i = degree; i > 0; --i){
        printf("%d X^%d + ", polynomial[i], i);
    }
    printf("%d\n", polynomial[0]);

    printf("The function's value of X=%d is %.3f\n", input, get_function_value2(polynomial, degree, input)); 
    */
    clock_t c1, c2;
    double t1, t2;
    c1 = clock();
    get_function_value1(polynomial, degree, input);
    c2 = clock();
    t1 = (c2 - c1)/(double)CLOCKS_PER_SEC;

    c1 = clock();
    get_function_value2(polynomial, degree, input);
    c2 = clock();
    t2 = (c2 - c1)/(double)CLOCKS_PER_SEC;

    
    printf("Degree : %d, Computing directly : %.3f(sec), Horner's method : %.3f(sec)\n", degree, t1, t2);

    free(polynomial);
}
