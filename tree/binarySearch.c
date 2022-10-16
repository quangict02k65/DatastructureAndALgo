#include<stdio.h>

#define max 100

//the binary search with input is array be sorted increasing order .
int binSearch(int low, int high, int arr[max], int x){

    if(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x )
            return mid;
        else if(arr[mid] > x)
            return binSearch(low, mid-1, arr, x);
        else 
            return binSearch(mid+1, high, arr, x);
    }
    else return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size, x = 4;
    size = sizeof(arr)/sizeof(arr[0]);

    printf("THe index of element %d in array is : %d", x, binSearch(0, size, arr, x));

    return 0;
}