#include<stdio.h>
#include<stdbool.h>

#define max 100


int count = 0;

void print(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

//check whether number is in column or not?
bool isPresentCol(int arr[9][9], int col, int  num){
    for(int r = 0; r < 9; r++){
        if(arr[r][col] == num){
            return true;
        }
    }
    return false;
}

//check whether number is in row or not?
bool isPresentRow(int arr[9][9], int row, int num){
    for(int c = 0; c < 9; c++){
        if(arr[row][c] == num){
            return true;
        }
    }
    return false;
}

//check whether num in present in 3x3 box or not
bool isPresentBox(int arr[9][9], int boxStartRow, int boxStartCol, int num){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(arr[row+boxStartRow][col+boxStartCol] == num){
                return true;
            }
        }
    }
    return false;
}

//check whether cell is empty or not?
bool findEmptyPlace(int arr[9][9], int row, int col){
    for(row = 0; row < 9; row++ ){
        for(col = 0; col < 9; col ++){
            if(arr[row][col] == 0){
                return true;
            }
        }
    }
    return false;
}

//check whether cell is valid
bool isValid(int arr[9][9],int row, int col, int num){
    //when item not found in col, row, and 3x3 box
    return !isPresentRow(arr,row,col) && !isPresentCol(arr,col,row) && !isPresentBox(arr,row-row%3, col-col%3, num);
}


bool sudoku(int arr[9][9]){
    int row, col;
    if(!findEmptyPlace(arr, row,col))
        return true;
    for(int num = 1; num <= 9; num++){
        if(isValid(arr, row, col, num)){
            arr[row][col] = num;
            if(sudoku(arr))
                return true;
            arr[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int arr[9][9];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d ", &arr[i][j]);
        }
    }
    if(sudoku(arr) == true)
        print(arr);
    else
        printf("No solution exitst\n");

    return 0;
}



