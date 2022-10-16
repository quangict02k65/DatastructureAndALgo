#include<stdio.h>

#define max 100

int n, M, N;
int x[max];
int count = 0;

void PrintSOlution(){
    for(int i = 1; i <= n; i ++){
        printf("%d  ", x[i]);
    }
    printf("\n");
}

int check(int j, int k){
    if( k == n)
        return (M+j == N);
    return 1;
}
// k la so phan tu da duoc chon truoc do
//M la tong so  hang da duoc chon
//n la so phan tu phai chon
void Try(int k){
    for(int j = 1; j <= (N-M)-(n-k) ; j++){
        if(check(j, k)){
            x[k] = j;
            M += j;
            if( k == n){
                PrintSOlution();
                count+=1;
            }
            else 
                Try(k+1);
            M -= j;
        }
    }
}

int main(){
    n = 5;
    N = 6;
    M = 0;
    printf("The solution of problem is : \n");
    Try(1);
    printf("Count : %d", count);
}