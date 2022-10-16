#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Need to declare: 
- the type of data in the node first
- then the linked list consists of data and the pointers to store the address
of the next node in the linked list
*/

//example
//struct student data type.

typedef struct student{
    char id[20];
    float math;
    float physics;
    struct student *next;
}student;
int main(){
    student* student1 = (student*)malloc(sizeof(student));
    // student1->data.id = "20205167";
    strcpy(student1->id,"20205167");
    student1->math = 10;

    printf("student with id %s  has math score: %f", student1->id, student1->math);
    return 0;
}