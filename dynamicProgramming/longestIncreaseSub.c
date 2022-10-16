
#include<stdio.h>
#include<stdlib.h>
 
/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */
  //using dynamic programming.
int lis(int arr[], int n)
{
    int lis[n];
 
    lis[0] = 1;
 
    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    // Return maximum value in lis[]

    for(int i = 0; i < n; i++){
        printf("%d \t", lis[i]);
    }
    
}

//use recursion.
int _lis(int arr[], int n){
    //base case.
    if(n == 1)
        return 1;
    
    //max_ending_here: length of LIS ending with arr[n-1]
    int temp, max_ending_here = 1;

//traversal all i to n-1 to find the maximum LIS.
    for(int i = 1; i < n; i++){
        //max_ref : oeverall maximum as the LIS may end with an element before arr[n-1].
        temp = _lis(arr, i);//L(i)
        if(arr[i-1] < arr[n-1] && temp + 1 > max_ending_here){
            max_ending_here = temp + 1;
        }
    }

    return max_ending_here;

}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 70, 45, 535, 34342 };
    int arr2[] = {1,2,3,4,3,2,3,4,2,6,23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) /  sizeof(arr2[0]);


    printf("Length of lis is : %d\n", _lis(arr, n));
    printf("lenth of lis 2 is : %d \n", _lis(arr2, n2));
 
    return 0;
}