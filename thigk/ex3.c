#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count[12];

void cpy(char *ptr,char* str,int start,int len){
    for(int i=0; i<len; i++){
        ptr[i] = str[start+i];
    }
    ptr[len] = '\0';
}

int main(){
    char str2[10];
    char str3[10];
    char str[1000];

    scanf("%s",str);

    while(strcmp(str,"$")!=0){
        cpy(str2,str,6,4);
        if(str[3] == '0') cpy(str3,str,4,1);
        else cpy(str3,str,3,2);
        if(strcmp(str2,"2020") == 0){
            
                count[atoi(str3)-1] ++;    
        }

        scanf("%s",str);
    }
    for(int i=0; i<12;i++){
        printf("%d ",count[i]);
    }
}