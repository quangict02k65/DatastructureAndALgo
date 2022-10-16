#include<stdio.h>

#define max 100

void linearSearch(int arr[max], int size, int x){
    int i; 
    for(i = 0 ; i < size; i++){
        if(arr[i] == x) 
            break;
    }
    if(i <= size)
        printf("The target is in the list index = %d", i+1);
    else 
        printf("The target is not in the list ");
}
int main(){
    int arr[] = {34,5,6,4,3,43,53,6,35,3};
    int size, x = 34;
    size = sizeof(arr)/sizeof(arr[0]);
    linearSearch(arr, size, x);

    return 0;
}