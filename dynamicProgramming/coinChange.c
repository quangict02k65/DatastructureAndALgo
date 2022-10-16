#include<stdio.h>
#include<stdlib.h>

int count(int *S, int m, int n){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if( m <= 0 && n >= 1)
        return 0;
    return count(S, m-1, n)+ count(S, m, n - S[m-1]);
}


//use dynamic programming tabular fashion.
int countDynamicTable( int S[], int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];
     
    // Fill the entries for 0
    //base case
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int main(){
    int S[] = {2,3,5,6};
    
    printf("The count is : %d\n", count(S, 4, 10));
    printf("The count (use dynamic programming talbe )is : %d\n", countDynamicTable(S, 4, 10));
    return 0;
}