#include<stdio.h>
#include<string.h>

#define max 100

int main(){
    char str[max][max],day[max][max], month[max][max], year[max][max];

    int count[12], cnt = 0;
    int i = 0;

    while(1+1 == 2){
        scanf("%s", str[i]);
        strncpy(day[i], str[i]+0,2 );
        strncpy(month[i], str[i]+3,2 );
        strncpy(year[i], str[i]+6,4 );
        i++;
        if(strcmp(str[i],"$") == 0){
            break;
        }
        cnt++;
    }
    return 0;
}