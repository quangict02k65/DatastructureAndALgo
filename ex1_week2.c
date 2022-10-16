#include<stdio.h>

int countNum(int n ){
    int i ;
    int total = 0;
    
    for(i = 1; i <= n; i++){
        if((i % 3 == 0 && i % 5 == 0) || (i % 3 == 2 && i % 5 == 3) ){
            total += i;
        }
        
        // if(i % 3 == 2 && i % 5 == 3){
        //     total += i;
        // }
    }
    return total;

}


int main(){
    int n; 

    printf("Enter the number n: ");
    scanf("%d", &n);

    printf("The value of function countNum is : %d\n", countNum(n));
    
    return 0;
}