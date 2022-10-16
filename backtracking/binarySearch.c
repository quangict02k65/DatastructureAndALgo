#include<stdio.h>


//write recursive function to solve binary search in ascending order
int binSearch(int low, int high, int s[], int key){
    if(low <= high){
        int mid = (low+high)/2;
        if(s[mid] == key) return mid;
        else if(key < s[mid])
            return binSearch(low, mid-1, s, key);
        else 
            return binSearch(mid+1, high, s, key);
    }
    else return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    printf("The index of element that has value equal 6 is : %d", binSearch(0,9,arr,6));
    return 0;
}
