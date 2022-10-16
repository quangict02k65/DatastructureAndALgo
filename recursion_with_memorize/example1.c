#include<stdio.h>
#include<string.h>
#include<time.h>

#define max 100
unsigned long long D[max][max];

// unsigned long long  C(int n , int k){
//    // if ( k == 0 || k == n)
//         //return 1;

//     return C(n - 1, k - 1) + C(n - 1, k);
// }

unsigned long long  C_mem(int n , int k){
    // if ( k == 0 || k == n)
    //     return 1;
    
    if(D[n][k] == 0)
        D[n][k] = C_mem(n-1, k -1 ) + C_mem(n-1 , k);

    return D[n][k];
}

int main(){
    int n, k;
    int n1 = 50, k1 = 20, n2 = 30, k2 = 25;

    //printf("The value of binomial coefficient of n1 = 20 and k1 = 15 is : %ld\n", C(n1, k1) );
    //0.023S
    //0.7S
    
    for (n = 0;n < max; n++){
        D[n][0] = 1;
        for(k = 1; k < max; k++){
            D[n][k] = 0;//set all element has value of 0;
            D[n][n] = 1;
        }
    }

    printf("The value of binomial coefficient of n1 = 50 and k1 = 20 is : %ld\n", C_mem(n1, k1) );


    return 0;
}