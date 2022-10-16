#include<stdio.h>

#define max 1000

// unsigned long long  C(int n , int k){
//     if ( k == 0 || k == n)
//         return 1;

//     else return C(n - 1, k - 1) + C(n - 1, k);
// }
int min(int a, int b){
    return (a<b) ? a : b;
}
//use dynamic programming
unsigned long long C(int n, int k){
    unsigned long long  value[n+1][k+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            value[i][j] = 0;
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(i,k); j++){ 
            if(j == 0 || j == i){
                value[i][j] = 1;
            }
            else{
                value[i][j] = value[i-1][j-1] + value[i-1][j];
            }
        }
    }
    return value[n][k];
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%lld", C(b,a));


    return 0;
}