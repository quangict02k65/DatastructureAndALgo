#include<stdio.h>

#define max 100

void merge(int arr[max], int l, int middle, int r ){
    int temArr[max];
    int id, id1, id2;

    id = 0; id1 = l; id2 = middle + 1;
    while(id1 <= middle && id2 <= r){
        if(arr[id1] < arr[id2]){
            temArr[id] = arr[id1];
            id1++;
            id++;
        }
        else{
            temArr[id] = arr[id2];
            id2++;
            id++; 
        }
    }

    for(; id1 <= middle; id1++){
        temArr[id] = arr[id1];
        id++;
    }
    for(; id2 <= r; id2++){
        temArr[id] = arr[id2];
        id++;
    }
    
    for(int i = l, id = 0; i <= r; i++, id++){
        arr[i] = temArr[id];
    }
}

void mergeSort(int arr[max], int l, int r){
    if(l < r){
        int middle = (l+r)/2;
        mergeSort(arr, l, middle);
        mergeSort(arr, middle+1, r);
        merge(arr, l, middle, r);
    }
}


void print(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {3,7,2,1,5,7,342,6,3,34,664};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorted is : \n");
    print(arr, n);
    printf("\n");
    mergeSort(arr, 0, n-1);
    printf("The array after sorted is : \n");
    print(arr, n);


}