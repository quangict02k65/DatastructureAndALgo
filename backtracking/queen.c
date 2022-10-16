#include<stdio.h>
#include<math.h>

#define max 100
int n;
//array a to be stored value of column of each row in chessboard.
int a[max];

void printSolution(){
    for(int i = 1; i <= n; i++){
        printf("(%d,%d)-->", i, a[i]);
    }
    printf("Done");
    printf("\n");
}

//check whether could place queen on cell( k,j)
int check(int k, int j){
    //check all k-1 row before , check whether row exited?
    for(int i = 1; i < k; i++){
        if((j == a[i]) || (abs(j - a[i]) == k-i ))
            return 0;
    }
    return 1;
}

void Try(int k){
    for(int j = 1; j <= n; j++){
        if(check(k, j)){
            a[k] = j;
            if(k == n)
                printSolution();
            else
                Try(k+1);
        }
    }
}



int main(){
    printf("Enter value of n :");
    scanf("%d", &n);
    printf("The solution of problem is : \n");
    Try(1);
    

}