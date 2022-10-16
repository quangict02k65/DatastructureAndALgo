#include<stdio.h>
#include<stdlib.h>


// void knapsackDyProg(int W[], int V[], int M, int n) {
// 	int B[size][size]; 
	
//     //initialize all start value as 0.
// 	for (int i=0; i<=n; i++)
// 		for (int j=0; j<=M; j++) {
// 			B[i][j] = 0;
// 		}
	
//     //as B[0][j] = 0;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j <= M; j++) {
// 			B[i][j] = B[i - 1][j];
			
// 			if ((j >= W[i-1]) && (B[i][j] < B[i - 1][j - W[i - 1]] + V[i - 1])) {
// 				B[i][j] = B[i - 1][j - W[i - 1]] + V[i - 1]; 
// 			}
// 			printf("%-3d  ", B[i][j]);
// 		}
// 		printf("\n");
// 	}
	
//     printf("Max value :  %d \n", B[n][M]);
// 	printf("Selected packages: \n");
	
// 	while (n != 0) {
// 		if (B[n][M] != B[n - 1][M]) {
//             printf("\t package %d with W = %d and value = %d\n", n, W[n-1], V[n-1]);
			
// 			M = M - W[n-1];
// 		}
		
// 		n--;
// 	}
// }

int knapsack_dynamic(int w[], int v[], int n, int W){
	int** K = NULL;
    K = (int **)malloc(n * sizeof(int *));

//allocate memory.
    for (int i = 1; i <= n; i++)
    {
        K[i] = (int *)malloc((W+1) * sizeof(int));
    }
//basic subproblem 
    for(int i = 1; i <= n; i++){
		K[i][0] = 0;
        for(int j = 0; j <= W; j++){
            if(w[1] <= j){
                K[1][j] = v[1];
            }
            else{
                K[1][j] = 0;
            }
        }
	}
//recursive problem.
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(j >= w[i] && (K[i-1][j-w[i]] +v[i]) > K[i-1][j]){
                 K[i][j] = K[i-1][j-w[i]]+v[i];
            }
            else{
                K[i][j] = K[i-1][j];
            }
        }
    }
    
	return K[n][W];
}



int main(){
    int w[] = {0,3,2,6,1,7,4};
    int v[] = {0,7,10,2,3,2,6};
	int n = 6, W = 10;

	printf("The maximum value is : %d", knapsack_dynamic(w, v, n, W));
    return 0;
}