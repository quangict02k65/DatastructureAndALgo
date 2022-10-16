#include<stdio.h>

#define max 100
int a[max], n;


/*
Problem to enumerate all binary string of length n leads to the enumeration of 
all elements of the set.
*/
//print all 
void PrintSolution(){
    for ( int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
    printf("\t");
}

void Try(int k ){
    //traversal all candidate of s[k].
    for (int y = 0; y <= 1; y++){
        a[k] = y;
        //if then complete solution.
        if(k == n-1 ) 
            PrintSolution();
        else Try(k + 1);
    }
}

int main(){

    printf("Enter value of n : "); scanf("%d", &n);
    printf("The solution of problem is : ");
    Try(0);

    return 0;
}