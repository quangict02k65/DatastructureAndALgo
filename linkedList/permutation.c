#include<stdio.h>

#define n 3


int arr[n];
void printSolution(){
    for(int i = 1; i <= n; i++){
        printf("%d", &arr[i]);
    }
    printf("\n");
}

int check(int k, int y){
    for(int y = 1; y <= k-1; y++){
        if(arr[y] == k)
            return 0;
    }
    return 1;
}

void try(int k){
    for(int i = 1; i <= n; i++ ){
        if(check(i,k))
            arr[k] = i;
                if(k == n-1)
                    printSolution();
                else 
                    try(k+1);

    }
}

int main(){
    try(0);

    return 0;
}