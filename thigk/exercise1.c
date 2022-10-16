#include<stdio.h>

#define MAX 100

int main(){
    int row, col, target;
    int check = 0;

	scanf("%d",&row);
	scanf("%d",&col);
	int arr[row][col];

	for(int i=0; i<row; i++){
		for(int j = 0; j < col; j++)
			scanf("%d",&arr[i][j]);
	}
	scanf("%d",&target);
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
		
			if(arr[i][j] == target){
				check=1;
				printf("%d %d", i+1, j+1);
				break;
			}
		}
		if(check == 1) break;
	}
	if(check ==0) 
        printf("-1 -1");
}