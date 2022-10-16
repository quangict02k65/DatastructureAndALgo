# include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a < b) ? a : b)


//use divide and conquer to solve this problem .
int makechange(int d[10], int n, int N){
    if(N == 0)
        return 0;
    else if(N < 0 || (N > 0 && n <= 0 ))
        return 1000;
    else{
        return min(makechange(d, n-1, N), makechange(d, n, N - d[n-1])+1);
    } 
}

//use dynamic programming
int knapsack_dynamic(int w[], v[], n, W){
    K = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        K[i] = (int *)malloc((W+1) * sizeof(int));
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(w[1] <= j){
                K[1, j] = v[1];
            }
            else{
                K[1, j] = 0l
            }
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= W; j++){
                if(j >= w[i] && K[i-1, j-w[i]+v[i]] + v[i] > K[i-1, j]){
                    K[i][j] = K[i-1, j-w[i] + v[i]];
                }
                else{
                    K[i][j] = K[i-1][j];
                }
            }
        }
    }
    return K[n, W];

}

//N:the amount of change to return 
//n: the number of different denominations(dinomination: menh gia).
int main(){
    int w[] ={3, 2, 6, 1, 7, 4}, n = 5, W = 10;
    int v[] = {7, 10, 2, 3, 2, 6};

    printf("THe maximum is : %d", knapsack_dynamic(w, v, n, W));


    return 0;
}