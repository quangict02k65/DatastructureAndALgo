#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a; 
    *a = *b; 
    *b =  temp;

}


typedef struct student{
    int id;
    char *name;
    int age; 
} stu;

int main(){
    int arr[] ={1,2,3,4,5,4,3,4,2};
    int *ptr;
    int x = 2323, y = 42424;
    printf("Before swap value of x is : %d, value of y is %d \n", x, y);
    swap(&x, &y);
    printf("After swap value of x is : %d, value of y is %d \n", x, y);

    ptr = arr; // assign pointer for array .
    printf("The value of the fourth element of array is : %d\n", ptr[3]);
    printf("The address of the fourth element is : %x\n", ptr+3);

//STRING AND STRUCT 
    char str[] = "nguyen ngoc quang";
    printf("String that you just entered be : %s\n", str);

    stu quang;
    quang.id = 20205167;
    quang.age = 20;
    quang.name = "nguyen ngoc quang";
    printf("Age of quang is : %d\n", quang.age);
    printf("Name of quang is : %s\n", quang.name);

    





    return 0;
}
