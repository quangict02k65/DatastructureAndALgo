#include<stdio.h>
#include<stdlib.h>

#define r 3
#define c 3
//write function to find minimum of 3 integers.
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

//recursion 
int minCost(int cost[r][c], int m, int n){
    if(m == 0  && n == 0){
        return cost[m][n];
    }
    else if(n < 0 || m < 0){
        return INT_MAX;
    }

    else{
        return cost[m][n] + 
        min(minCost(cost, m-1, n-1), minCost(cost, m-1, n), minCost(cost, m, n-1));
    }
}

int minCostTabular(int cost[r][c], int m, int n)
{
     int i, j;
 
     // Instead of following line, we can use int tc[m+1][n+1] or
     // dynamically allocate memory to save space. The following line is
     // used to keep the program simple and make it working on all compilers.
     int tc[r][c]; 
 
     tc[0][0] = cost[0][0];
 
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];
 
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];
 
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1],
                           tc[i - 1][j],
                           tc[i][j - 1]) + cost[i][j];
 
     return tc[m][n];
}

int main(){
    int m = 2, n = 2;
    int cost[r][c] = {{1,2,3}, {4,8,2}, {1,5,3}};
    
    printf("The minimum path cost equal: %d\n", minCost(cost, m, n));
    printf("The minimum path cost(tabular dynamic programming) equal: %d\n", minCostTabular(cost, m, n));

    return 0;
}