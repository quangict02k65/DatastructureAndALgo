#include<stdio.h>
#include<stdlib.h>

long long F[1005];


//bulil fibonacci problem by dynamic programming .

//b1: định nghĩa bài toán con nhỏ nhất.
//b2: giải bài toán cơ sở
//b3: xác định đáp án bài toán 
//b4: xây dựng công thức truy hồi.

//memorize
long long fibo(int n ){
    if(F[n] != 0){
        return F[n];
    }
    //basic subproblem 
    if(n == 0 || n == 1){
        return 1;
    }
    //stored value in tabular through recursive tech.
    F[n] = fibo(n-1) + fibo(n-2);

    return fibo(n-1) + fibo(n-2);
}

 //tabular
 long long fibo2(int n){
     long long* f = (long long*)malloc((n+1)* sizeof(long long));
     f[0] = 0;
     f[1] = 1;
     for(int i = 2; i <= n; i++){
         f[i] = f[i-1] + f[i-2];
     }

     return f[n];
 }

int main(){
    int n =  200;

    for(int i = 0; i <= n; i++){
        F[i] = 0;
    }
    printf("the result of fibo(%d) (use memorize fashion) is : %lld \n",n,  fibo(n));
    printf("The result of fibo(%d) ( use tabular fashion ) is : %lld \n",n, fibo2(n));

    return 0;
}