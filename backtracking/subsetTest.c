#include<stdio.h>

#define max 50
int arr[max], n, m;

//problem enumerate all m element subsets of the set n elements 
//N = {1,2,3,4,5,6,7,...,n}

void printSolution(){
    int i; 
    for(i = 1; i <= m; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int j = arr[k-1]+1; j <= n - m + k; j ++){
        arr[k] = j;
        if(k == m){
            printSolution();
        }
        else{
            Try(k+1);
        }
    }
}

int main(){
    printf("Enter n : "); scanf("%d", &n);
    printf("Enter m : "); scanf("%d", &m);
    printf("All subset that need find is : ");
    Try(1);

    return 0;
}