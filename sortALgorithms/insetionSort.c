#include<stdio.h>

/// idea: chia hai tập , sorted list and unsorted list
// duyệt n -1 vòng lặp , vói mỗi phần tử đầu tiên của unsorted list thì ta so sánh với các phần tử trong sorted list, nếu nhỏ hơn thì đổi chỗ 
//c1: 
void insertionSort(int *arr, int n){
    for(int k = 1; k < n; k++){
        int j;
        for(j = k - 1; j >= 0; j--){
            if(arr[j] < arr[k])
                break;
        }
        int temp = arr[k];
        for(int i = k; i >= j+2; i--)
            arr[i] = arr[i-1];
        arr[j+1] = temp;
    }
}

//c2:
void insertionSort2(int *arr, int n){
    for(int k = 1; k < n; k++){
        int temp = arr[k];
        int j = k-1;
        while(temp  < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = temp;
    }
}

void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}


int main(){
    int arr[] = {1,5,3,5,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    //insertionSort2(arr,n);
    insertionSort(arr, n);
    //fselectionSort(arr, n);
    print(arr,n);
    return 0;
}