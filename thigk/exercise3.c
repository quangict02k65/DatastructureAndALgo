#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>


#define max 100

int main(){
    char str[max][max],day[max][max], month[max][max], year[max][max];

    int count[12], cnt = 0;
    int i = 0;

    do{
        scanf("%s", str[i]);
        strncpy(day[i], str[i]+0,2 );
        strncpy(month[i], str[i]+3,2 );
        strncpy(year[i], str[i]+6,4 );
        cnt++;
        if(strcmp(str[i], "$") != 0){
            i++;
        }
    }
    while(strcmp(str[i], "$") != 0);

    // for(int i = 0; i < cnt; i++){
    //     if(strcmp(year[i], "2020") == 0 ){
    //         for(int j = 0; j < 12; j++){
    //             int num = atoi(month[i]);
    //             if(num == (j+1)){
    //                 count[j]++;
    //             }
    //            // if(strcmp(month[i], ""))
    //         }
    //     }
    // }
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < cnt; j++){
            if(strcmp(year[j], "2020") == 0){
                int num = atoi(month[j]);
                if(num == (i+1)){
                    count[i] ++;
                }20
            }
        }
    }
    for(int i = 0; i < 12; i++){
        printf("%d ", count[i]);
    }
    return 0;
}