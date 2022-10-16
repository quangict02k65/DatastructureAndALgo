#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

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
    int n, m, M;
    int arr[100];
    // char filename[40];
    FILE *fp = NULL; 

    char str[10];
    //str = (char) n;
    //filename = strcat("arr-", str);
    fp = fopen("fileArr.txt", "w");
    scanf("%d %d %d", &n, &m, &M);
    fprintf(fp, "%d %d %d \n", n, m, M);
    for(int i = 0; i < n; i++){
        arr[i] = (rand()%(M-n+1)) + n;
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp, "%s", "Mang sau khi sap xep la : \n");

    mergeSort(arr, m, M);
    for(int i = 0; i < n; i++){
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);


    // FILE *f = NULL:
    // f = fopen("fileArr.txt", "r");

    // while()


}