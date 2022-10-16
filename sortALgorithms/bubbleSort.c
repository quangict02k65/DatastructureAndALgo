#include<stdio.h>

//each iteration => select the largest element at last array.
void bubbleSort(int *arr, int n){
    int i, j;
    int sorted = 1;
    for(i = 0; i < n; i ++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = 0;
            }
        }
        if(sorted == 1) return ;
    }
}

void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {23,21,36,75,11,24,2,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorted is : \n");
    print(arr, n);
    bubbleSort(arr, n);
    printf("\n");
    printf("The array after sorted is : \n");
    print(arr, n);

}