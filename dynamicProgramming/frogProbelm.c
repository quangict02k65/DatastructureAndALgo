#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define min(a, b) a > b ? b : a
int F[1005];
//incurred: được phát sinh(cost).
/*
Problem: there are n stones, numbered 1,2, 3, ..., n . for each i , hi is the height of stone i
there is a frog who is initially on stone 1 . he will repeat the following action some number of times
to reach stone n.
If the frog is currently on stone i, jump to stone i+1 or stone i+2 , here , a cost of
|hi-hj| is incurred, where j is the stone to land on.
find the minimum possible total cost incurred before the frog reaches stone n.
*/


//bulil fibonacci problem by dynamic programming .

//b1: định nghĩa bài toán con nhỏ nhất.
//b2: giải bài toán cơ sở
//b3: xác định đáp án bài toán 
//b4: xây dựng công thức truy hồi.
int frogProblem(int n, int *w){
    if(n == 1)
        return 0;
    if(n == 2)
        return w[1] - w[0];
    for(int i = 2; i < n; i++){
        F[i] = min(F[i-1] + abs(w[i] - w[i-1]), F[i-2] + abs(w[i] - w[i-2])); 
    }
    return F[n-1];
}
int main(){
    int w[] = {30, 10, 60, 10, 60, 50};
    int n = 6;

    printf("Min cost is : %d", frogProblem(n, w));

    return 0;
}