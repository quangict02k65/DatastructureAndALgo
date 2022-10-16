#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

int palindrome(char str[MAX_SIZE], char start, char end){
    if(start >= end) return 1;

    if(str[start] == str[end]){
            return palindrome(str, start+1, end-1 );
    }
    else return 0;
}

int main(){
    char str[] = "able was i ere i saw elba";
    char str2[] = "qwertyuioppoiuytrewq";
    //printf("do dai cua xau la : %d", strlen(str));

    int result ;
    result = palindrome(str, 0, strlen(str)- 1);

    if(result){
        printf("String \"%s\" is palindrome", str);
    }
    else printf("String \"%s" is not a palindrome ", str);



    return 0;
}