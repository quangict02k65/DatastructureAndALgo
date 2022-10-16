#include<stdio.h>

#define max 100
int a[max];
int n;

void PrintSolution(){
    for ( int i = 1;i <= n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

int check(int y, int k){

        if(a[k-1] + y > 1)
            return 0;

    return 1;
}

void Try(int k ){
        for ( int y = 0; y <= 1; y++){
            if(check(y, k) == 1){
                a[k] = y;

                if(k == n ) 
                    PrintSolution();
                else Try(k + 1);
            }
        }
}



int main(){
    n = 5;
    Try(1);
    return 0;
}