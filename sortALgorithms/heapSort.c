#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void MAX_HEAPIFY(int arr[], int i, int n){
    int leftchild = 2*i+1;
    int rightchild = 2*i+2;
    int largest = i;
    if(leftchild < n && arr[leftchild] > arr[i])
        largest = leftchild;
    if(rightchild < n && arr[rightchild] > arr[largest])
        largest = rightchild;
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        MAX_HEAPIFY(arr, largest, n);
    }

}

void BuilMaxHep(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i --){
        MAX_HEAPIFY(arr, i, n);
    }
}

void HeapSort(int arr[], int n){
    BuilMaxHep(arr, n);
    for(int i = n - 1; i >= 1; i --){
        swap(&arr[0], &arr[i]);
        MAX_HEAPIFY(arr, 0, i);
    }
}

void print(int *arr, int size){
    int i ; 
    for(i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

int main(){
    int arr[] = {3,53,52,23,1,21,34,12,11,67,534};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorted is : ");
    print(arr, size);
    printf("\nTHe array after sorted by heapsort is : ");
    //quickSort(arr, 0, size-1);
    //quickSort2(arr, 0, size-1);
    HeapSort(arr, size);
    print(arr, size);

    return 0;
}