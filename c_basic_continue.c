#include<stdio.h>
#include<stdlib.h>
//cấp phát bộ nhớ (allocate memory)

int main(){

    //DYNAMIC ALLOCATION : bộ nhớ động 
    /*
    đôi khi khai báo một mảng thì chúng ta k biết chính xác số phần tử của mảng 
    là bao nhiêu
    do đó ta sử dụng bộ nhớ động để k lo nó có đủ dài hay có thể giải phóng nó 
    khi không sử dụng nữa.
    */
// //malloc
//     int *ptr = (int*) malloc(25 * sizeof(int )); //cấp phát bộ nhớ gồm 25 số nguyên 
//     printf("%x\n", ptr);
// //calloc
//     /*
//     like malloc, calloc is used for dynamic memory allocation howerver the entire
//     memory allocated by the calloc() function will be assigned the value 0
//     */

//     int *ptr2 = (int*) calloc(25, sizeof(int));
 
//     /*
//     unlike the local variable and parameter of a function located on the stack memory 
//     (which will be automaticaaly released as soon as it goes out of the scope of that func 
//     dynamically allocated memory on the heap will not be freed
//     if not released, the program may get memory leak
//     to free memory allocated by malloc(),.. we use the free() function 
//     */


//     //REALLOC()
//     //realloc(re allocation ): reallocate on the previous allocated memory area because
//     //the previous allocated memory area is not enough or too large
//     ptr = (int*) realloc(pointer, 20*sizeof(int));


    //exercise: enter a sequence of integers from the keyboard ,print the numbers 
    //in reverse order, requires use of dynamic allocation 

    int i, n, *p;

    printf("Enter number of elements of array =  ");
    scanf("%d", &n);

    p = (int *)malloc(n  * sizeof(int ));


    if(p == NULL){
        printf("Allocate not successfull \n");
        return 1;
    }

    
    for (i = 0; i < n; ++i)
    {
        scanf("%d", p + i);
    }

    for(i = 0; i < n; i++){
        printf("arr[%d] = %d", i+1, *(p+i));
    }
    free(p);
    return 0;
}