#include<stdio.h>
#include<time.h>


#define max 100000

void bruteForce(int arr[], int n, int q){
    int i, j;
    int count = 0;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] + arr[j] == q){
                count ++;
            }
        }
    }
    printf("Number of pair is : %d\n", count);
}

// void quickSort(int arr[], int left, int right){
//     if(left < right){
//         int indexPivot = partition(arr, left, right);
//         quickSort(arr, left, indexPivot - 1);
//         quickSort(arr, indexPivot + 1, right);
//     }
// }

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

// int partition(int arr[], int l, int r){
//     int i, j;
//     int pivot = arr[l];

//     i = l + 1; j = r;
//     while(i <= j){
//         while(i <= r && arr[i] < pivot){
//             i ++ ;
//         }
//         while( j >= l && arr[j] > pivot ){
//             j --;
//         }
//         if(i < j){
//             swap(&arr[i], &arr[j]);
//         }
//         else break;
//     }
//     //swap arr[indexPivot ] and arr[]
//     swap(&arr[l], &arr[j]);

//     return j; 
// }

void sort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int target){
    int middle = (low + high) /2;

    if(low > high )
        return 0;
    if( low == high){
        if(arr[low] == target){
            return 1;
        }
        else return 0;
    }

    if(arr[middle] == target)
        return 1;
    if(arr[middle] < target)
        return binarySearch(arr, middle+1, high, target);
    return binarySearch(arr, low, middle-1, target);
}

void binarySearchSolve(int arr[], int n, int q){
    sort(arr, n);
    int count = 0;

    for(int i = 1; i < n; i++){
        int tmp = binarySearch(arr, i+1, n, q-arr[i]);
        count += tmp;
    }
    printf("The number of pair is : %d\n", count);
}


int main(){
    int arr[max];
    int q = 6;
    char filename[256]; 
    printf("Enter file name : ");
    scanf("%s", filename);
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        printf("Not found file !!!!\n");
    }
    int size;

    while(!feof(f)){
        fscanf(f, "%d", &size);
        for(int i = 0; i < size; i++){
            fscanf(f, "%d ", &arr[i]);
        }
    }
    fclose(f);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
   // binarySearchSolve(arr, size, q);
    double time_spent = 0.0;
 
    clock_t begin = clock();
 
    // do some stuff here
    bruteForce(arr, size, q);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent); //0.118s

    // double time_spent = 0.0;
 
    // clock_t begin = clock();
 
    // // do some stuff here
    // binarySearchSolve(arr, size, q);
 
    // clock_t end = clock();
 
    // // calculate elapsed time by finding difference (end - begin) and
    // // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    // printf("The elapsed time is %f seconds", time_spent);//0.149s

}