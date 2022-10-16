#include<stdio.h>
#include<string.h>

//write recuisive function to check whether string is palindrome?
int checkPlindrome( char *str, int start, int end){
    if(start >= end)
        return 1;
    else{
        if(str[start] == str[end] )
            return checkPlindrome(str, start + 1, end -1 );
        else return 0;
    }
}

int main(){
    char str[] = {"quanggnauqf"};
    
    if(checkPlindrome(str, 0, strlen(str) - 1))
        printf("String is palindrome");
    else 
        printf("No");
}