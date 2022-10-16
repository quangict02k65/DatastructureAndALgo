#include<stdio.h>
#include<stdlib.h>


//Problem.
/*
given a sequence of matrices, find the most efficient way to multiply these matrices together.
The problem is not actually to perform the multiplications, but merely to decide in which order 
to perform the multiplications.
product matric property: (ABC)D = (AB)(CD)
purpose: the order in which we parenthesize the prodict affects the number of simple arithmetic
operations needed to compute the product, or the efficiency.
arithmetic operations needed to compute the product, or the efficiency. 
For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
*/

//input: p[] = {40,20,30,10,30}
//output: 26000. (A(BC))D


//use recursion
int matrixChainorder(int *p, int i, int j){
    int k;
    int min = INT_MAX;
    int count;

    if( i == j)
        return 0;

    for(int k = i; k < j; k++){
        count = matrixChainorder(p, i, k) +
        matrixChainorder(p, k+1, j) + p[i-1] * p[k] * p[j];
        if(count < min){
            min = count;
        }
    }
    return min;
}

//use dynamic programming tabular
int matrixDynamic(int p[], int n){
    int m[n][n];

    int i, j, k, L, q;
    for(int i = 1; i < n; i++){
        m[i][i] = 0;
    }

    for(L = 2; L < n; L++){
        for(int i = 1; i < n - L +1; i++){
            j = i + L -1;
            m[i][j] = INT_MAX;
            for(k = i; k <= j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if( q < m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int matrixTable(int *d, int n){
    int M[n][n], min;
    //base case.
    for(int i = 1; i <= n; i++){
        M[i][i] = 0;
    }

//stored all element in table.
    for(int s = 1; s < n; s ++){
        for(int i = 1; i <= n-s; i++){
            min = INT_MAX;
            //i+s = j.
            for(int k = i; k < i + s; k++){
                if(M[i][k] + M[k+1][i+s] +d[i-1]*d[k]*d[i+s] < min ){
                    min = M[i][k] + M[k+1][i+s] + d[i-1]*d[k]*d[i+s];
                }
            }
         M[i][i+s] = min;
        }
    }
    return M[1][n-1];   
}



int main(){ 
    int p[] = {40, 20, 30, 10, 30};
    int p2[] = {4, 10, 3, 12, 20, 7};
    int n2 = sizeof(p2)/sizeof(p2[0]);
    int n = sizeof(p)/sizeof(p[0]);
    printf("The min(use recursion ) is : %d\n", matrixChainorder(p, 1, 4));
    printf("The min ( use dynamic programming tabular ) is : %d\n", matrixDynamic(p2, 6));
    printf("The min(use dynamic programming tabular tulu ) is : %d\n", matrixTable(p, 5));
    matrixTable(p2,n2);

    return 0;
}