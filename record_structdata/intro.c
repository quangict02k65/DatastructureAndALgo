#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int id; 
    char* name;
    char grade;
} student;

int main(){
    student* quang;
    int diem;
    quang = (student*) malloc(sizeof(student)); // cap phat bo nho cho con tro

    quang->name  = "nguyen ngoc quang";
    printf("Ten cua quang la : %s\n", quang->name);

    printf("nhap vao so diem cua quang\n");
    scanf("%d", &diem);
    quang->grade = diem;
    printf("so diem cua quang la : %d\n", quang->grade);

    return 0;
}