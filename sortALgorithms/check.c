#include<stdio.h>


int Fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else{
       return Fibonacci(n-1) + Fibonacci(n-2); 
    }
}

int main()
{
	int i;
    for (i = 0; i < 1000; i++) {
        printf("%d\n", Fibonacci(i));
    }
    return 0;
}