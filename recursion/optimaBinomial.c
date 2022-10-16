#include <stdio.h>
#include<string.h>

int min(int a, int b){
    return (a<b)?a : b;
}

int binomialCoeff(int n, int k)
{
    int C[k + 1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // nC0 is 1
 
    for(int i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using
        // the previous row
    for(int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

 
/* Driver code*/
int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    printf("%d", n, k,
           binomialCoeff(n, k));
    return 0;
}