#include<stdio.h>
#include<stdlib.h>

//comparing the running time of two algorithms . 
#define max 100

void selectionSort(int *arr, int n){
    int  minj, minx;

    for(int i = 0; i < n-1; i++){
        minj = i; 
        minx = arr[i];
        for(int j = i+1; j < n; j++){
            if(arr[j] < minx){
                minj = j; 
                minx = arr[j];
            }
        }
        arr[minj] = arr[i];
        arr[i] = minx ; 
    }

}

void insertionSort(int *arr, int n ){
    int j , v; 
    for(int i = 1; i < n; i++){
        v = arr[i]; 
        j = i - 1; 
        while(j >= 0 && arr[j] > v){
            arr[j+1] = arr[j];
             j --; 
        }
        arr[j+1] = v;
    }
}

int main(){
    int arr[] = {3,2,6,7,8,3,4,6};
    int n = sizeof(arr) /sizeof(arr[0]);
    printf("After sorting increase is : ");
    // selectionSort(arr, n);
    // for(int i = 0; i < n ; i++){
    //     printf("%d ", arr[i]);
    // }
    insertionSort(arr, n);
    for(int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}