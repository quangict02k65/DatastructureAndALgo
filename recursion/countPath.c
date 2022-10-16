#include<stdio.h>

int countPath(int i, int j, int D, int C){
    if(i > D || j > C )
        return 0;
    else{
        if(j == D || i == C)
            return 1;
        else 
            return countPath(i+1, j, D, C) + countPath(i, j+1, D, C);
    }
}


int main(){
    int i, j, D, C;

    printf("Enter position start following format(i j) : \n");
    scanf("%d %d", &i, &j);

    printf("Enter position end following format(C D) : \n");
    scanf("%d %d", &D, &C);
    
    printf("The number of count path from (i,j) to (C,D) is : %d", countPath(i,j,D,C));





    return 0;
}