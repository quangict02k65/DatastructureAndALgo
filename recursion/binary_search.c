#include<stdio.h>

int binary_search(int low, int high, int  arr[], int key){
    int mid = (low+high)/2;

    if(low <= high){
        if(key == mid) return mid;
        if(key < mid){
            return binary_search(low, mid-1, arr, key);
        }
        else{
            return binary_search(mid+1, high, arr, key);
        }
    }
    else return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,56,78};
    int key = 4;

    printf("Index of value key is :%d", binary_search(0, 9, arr, key));
}