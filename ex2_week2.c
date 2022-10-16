#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i , j, k;
    int **arr1, **arr2, **arr_product;

    do{
        printf("Enter the integer number(n >= 2): ");
        scanf("%d", &n);
        
        if(n < 2){
            printf("N must be greater or equal to 2. Please re-enter n : \n");
        }
    }
    while( n < 2);

    arr1 = malloc(sizeof(int *) * n);
    arr2 = malloc(sizeof(int *) * n);
    arr_product = malloc(sizeof(int *) * n);
    
    /*Cấp phát bộ nhớ động cho n mảng con, mỗi mảng gồm n phần tử,
    để chứa n phần tử tương ứng trong từng hàng của mảng 2 chiều cần tạo*/
    /*Gán địa chỉ của các mảng này vào phần tử của mảng mẹ*/
    for(int i = 0; i < n; i++) {
        arr1[i] = malloc(sizeof(int *) * n); 
        arr2[i] = malloc(sizeof(int *) * n);
        arr_product[i] = malloc(sizeof(int *) * n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("arr1[%d][%d] = ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("arr2[%d][%d] = ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }


    printf("Product matrix is : \n");
    for( i = 0; i < n; i++){
        for( j = 0; j < n; j++){
            arr_product[i][j] = 0;
            for(k = 0; k < n; k++){
                arr_product[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d \t", arr_product[i][j]);
        }
        printf("\n");
    }
     

    return 0;
}