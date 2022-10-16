#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define max(a,b) a > b ? a : b
//find the length of longest subsequence present in both of them.

int lcs(char *X, char *Y, int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }
    if(X[m-1] == Y[n-1]){
        return 1 + lcs(X, Y, m-1, n-1);
    }
    else{
        return max(lcs(X, Y, m-1, n), lcs(X, Y, m, n-1));
    }
}

//using dynamic programming through tabular
int lcs2( char *X, char *Y, int m, int n ){
    int L[m+1][n+1];
    int i, j;
 
/* Following steps build L[m+1][n+1] in bottom up fashion. Note
    that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            //basic problem
        if (i == 0 || j == 0)
            L[i][j] = 0;
    //recursively problem .
        else if (X[i-1] == Y[j-1])
            L[i][j] = L[i-1][j-1] + 1;
    
        else
            L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
     
/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
//result of problem: L[m][n];
return L[m][n];
}

//dynamic memorize fashion
int lcs3(char* X, char* Y, int m, int n, int** dp){
//base case.
    if (m == 0 || n == 0)
        return 0;
        // check dp[][] != NIL
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs3(X, Y, m - 1, n - 1,dp);

    else
        return dp[m][n] = max(lcs3(X, Y, m, n - 1, dp),
                          lcs3(X, Y, m - 1, n ,dp));
}

int main(){
    char X[] = "abcdgh";
    char Y[] = "aedfhr";

    int m = strlen(X);
    int n = strlen(Y);

    int **dp;
    dp = (int**)malloc((m+1)*sizeof(int*));

    for(int i = 0; i <= m; i++){
        dp[i] = (int*)malloc((n+1)*sizeof(int));
    }

    for(int i = 0; i <= m; i ++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    printf("Length of LCS(recursion algorithms) is : %d\n", lcs(X, Y, m, n));
    printf("Length of LCS(dynamic programming tabular) is : %d\n", lcs2(X, Y, m, n));
    printf("length of LCS(dynamic programming memorize) is : %d \n", lcs3(X, Y, m, n, dp));

    return 0;
}