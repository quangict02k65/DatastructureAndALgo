#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int min(int x, int y, int z){
    if(x <= y && x <= z)
        return x;
    else if(y <= x && y <= z)
        return y;
    else return z;
}

int editDist(char* str1, char* str2, int m, int n){
//basic problem
    if( m == 0)
        return n;
    if(n == 0 )
        return m;

    //recursively problem.
    if(str1[m-1] == str2[n-1])
        return editDist(str1, str2, m-1, n-1);
    else{
        return 1 + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,n - 1)); // Replace
    }
}


//using dynamic programming
int editDistDP(char* str1, char* str2, int m, int n)
{
    // Create a table to store results of subproblems
    int** dp = (int**)malloc((n+1) * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        dp[i] = (int *)malloc((m+1) * sizeof(int));
    }
 
    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
        }
    }
 
    return dp[m][n];
}

int main(){
    char str1[] = "sunday";
    char str2[] = "saturday";

    int m = strlen(str1);
    int n = strlen(str2);

    printf("%d\n", min(2,3,4));

    printf("The minimum is : %d", editDistDP(str1, str2, m, n));


    return 0;
}