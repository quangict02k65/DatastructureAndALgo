#include<stdio.h>


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest ])
        largest = left;
    if(right < n  && arr[right] > arr[largest ])
        largest = right;
    if(largest != i ){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//to buil heap , we call heapify function with every node expect leaf node.
void buildMaxHeap(int arr[], int n){
    for(int i = n/2 -1 ; i >= 0; i--){
        heapify(arr, n, i);
    }
}


/*
with heap sort : 
- because the largest element located at root node
we swap the root and the last element 
after that ,we delete the last element in heap 
we heapify new heap and repeat all above step.
*/
void heapSort(int arr[], int n){
    //build max-heap
    buildMaxHeap(arr, n);

    //heap sort
    for(int i = n - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        //heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {2,3,64,234,23,5,767,23,12,43};
    int size = sizeof(arr)/ sizeof(arr[0]);

    heapSort(arr, size);
    printf("Array after sorted is : ");
    printArray(arr, size);
    return 0;
}