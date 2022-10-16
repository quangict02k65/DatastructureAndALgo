#include<stdio.h>

void selectionSort(int *arr, int n ){
    int i, j, smallest, temp, indx;

    for(i = 0; i < n-1; i++){
        smallest = arr[i], indx = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < smallest ){
                smallest = arr[j];
                indx = j;
            }
        }
        temp = arr[indx];
        arr[indx] = arr[i];
        arr[i] = temp;
    }
}

void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {2,6,2,1,97,34,22};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorted is : \n");
    print(arr, n);
    selectionSort(arr, n);
    printf("\n");
    printf("The array after sorted is : \n");
    print(arr, n);

}