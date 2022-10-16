#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void cpy(char *ptr,char* str,int start,int len){
    for(int i=0; i<len; i++){
        ptr[i] = str[start+i];
    }
    ptr[len] = '\0';
}

int main(){
    char string[] = "nguyenngocquang 20205167";
    char *p = strtok(string, " ");
    char str1[245], str2[344];
    strcpy(str1, p);
    p = strtok(NULL, " ");
    strcpy(str2, p);
    printf("String 1 is : %s\n String 2 is : %s", str1, str2);
    return 0;
}