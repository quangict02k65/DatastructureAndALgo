#include<stdio.h>


void quickSort(int *arr, int left, int right){
    if(left < right){
        int indexPivot = partition(arr, left, right);
        quickSort(arr, left, indexPivot - 1);
        quickSort(arr, indexPivot + 1, right);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int partition(int *arr, int l, int r){
    int i, j;
    int pivot = arr[l];

    i = l + 1; j = r;
    while(i <= j){
        while(i <= r && arr[i] < pivot){
            i ++ ;
        }
        while( j >= l && arr[j] > pivot ){
            j --;
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
        else break;
    }
    //swap arr[indexPivot ] and arr[]
    swap(&arr[l], &arr[j]);

    return j; 
}

//choose pivot at right position
int partitionRight(int *arr, int l, int r){
    int i, j;
    int pivot = arr[r];

    i = l ; j = r-1;
    while(i <= j){
        while(i <= r && arr[i] < pivot){
            i ++ ;
        }
        while( j >= l && arr[j] > pivot ){
            j --;
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
        else break;
    }
    //swap arr[indexPivot ] and arr[]
    swap(&arr[r], &arr[i]);

    return i; 
}

void quickSort2(int *arr, int left, int right){
    if(left < right){
        int indexPivot = partitionRight(arr, left, right);
        quickSort2(arr, left, indexPivot - 1);
        quickSort2(arr, indexPivot + 1, right);
    }
}

void print(int *arr, int size){
    int i ; 
    for(i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

//choose pivot at middle
int partitionMiddle(int *arr, int l, int r){
    int i, j;
    int middle = (l+r)/2;
    int pivot = arr[middle];

    i = l ; j = r;
    while(i <= j){
        while(i <= middle && arr[i] <= pivot){
            i ++ ;
        }
        while( j >= middle && arr[j] > pivot ){
            j --;
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
        else break;
    }
    //swap arr[indexPivot ] and arr[]
    swap(&arr[middle], &arr[j]);

    return j; 
}

void quickSort3(int *arr, int left, int right){
    if(left < right){
        int indexPivot = partitionMiddle(arr, left, right);
        quickSort3(arr, left, indexPivot - 1);
        quickSort3(arr, indexPivot + 1, right);
    }
}


int main(){
    int arr[] = {3,53,52,23,1,21,34,12,11,67,534};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorted is : ");
    print(arr, size);
    printf("\nTHe array after sorted by quicksort is : ");
    //quickSort(arr, 0, size-1);
    //quickSort2(arr, 0, size-1);
    quickSort3(arr, 0, size-1);
    print(arr, size);

    return 0;
}