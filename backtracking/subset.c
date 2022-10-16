#include<stdio.h>

#define max 100
int a[max], n, m;

void PrintSolution(){
    for ( int i = 1;i <= m; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

void Try(int k){
    for( int y = a[k-1]+1; y <= n-m+k; y++ ){
        a[k] = y;
        if(k == m)
            PrintSolution();
        
        else 
            Try(k+1);
    }
}
int main(){
    //a[]  = {1,2,3,4,5};
    n = 5, m = 3;
    Try(1);

    return 0;
}