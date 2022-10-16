#include<stdio.h>


int calculate_sum(int n){
    if( n == 1) return 1;

    return n + calculate_sum(n-1);
}

int factorial(int n){
    if(n == 0) return 1;

    return n * factorial(n-1);
}
int main(){

    int n  = 10;

    printf("Sum of array is : %d\n", calculate_sum(4));
    printf("Factorial of %d is %d \n", n, factorial(n));
    return 0;
}