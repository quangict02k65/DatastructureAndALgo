//kiem tra .

#include<stdio.h>

#define size 5


int Product(int list[size], int k ){
    if(k == (size-1)){
        return list[k];
    }
    else 
        return list[k] * Product(list, k+1) ;
}

int main(){
    int arr[size], i;

    for(i = 0; i < size; i++){
        printf("Enter arr[%d] = ", i+1);
        scanf("%d", &arr[i]);
    }


    printf("Product of all element of array is : %d", Product(arr, 0));
    return 0;
}