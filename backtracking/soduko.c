#include<stdio.h>
// N is the size of the 2D matrix   N*N
#define N 9
int x[N][N];
 
/* A utility function to print grid */
void printSolution(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }
}

int check(int v, int r, int c){
    for( int i = 0; i <= r-1; i++){
        if(x[i][c] == v)
            return 0;
    }

    for(int j = 0; j <= c-1; j++){
        if(x[r][j] == v) 
            return 0;
        
    }

    int I = r/3;
    int J = c/3;
    int i = r - 3*I;
    int j = c - 3*J;

    for (int i1 = 0; i1 <= i-1; i1++){
        for(int j1 = 0; j1 <= 2; j1++){
            if(x[3*I+i1][3*J+j1] == v)
                return 0;
        }
        for(int j1 = 0; j1 <= j-1; j1++){
            if(x[3*I+i][3*J+j1] == v)
                return 0;
        }
    }
    return 1;
}

void try(int r, int c){
    for(int v = 1; v <= 9; v++){
        if(check(v,r,c)){
            x[r][c] = v;
            if(r == 8 && c == 9)
                printSolution(x);
            else 
                if(c == 8)
                    try(r+1, 0);
                else 
                    try(r, c+1);
        }
    }
}

int main(){

    /*
    Backtracking algorithms  
    */
    try(0,0);
    return 0;
}