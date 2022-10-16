#include<stdio.h>
#include<string.h>
#include<math.h>

#define max 256
#define ULL unsigned long long 

//length of string is <= 200.

//give a string s[1...k] is a sequece of characters taken from a to z .
/*
given a positive integer m, the hash code of s is defined by the formula
*/
int hashFunction(char *str, int m){
    int leng = strlen(str);
    int hashValue = 0;
    int intercept = 1;

    while(leng > 0){
        int number = (intercept * (int) str[leng - 1] );
        hashValue += number % m;
        intercept = ((intercept % m) * 256) % m; 
        leng --;
        //hashValue = hashValue % (m*10);
    }
    return hashValue % m;
}


int main(){
    long long n ;
    int m;
    char str[max];
    long long i = 0;
    scanf("%lld %d", &n, &m);

    while(i < n){
        scanf("%s[^\n]%*c", str);
        printf("%d\n", hashFunction(str, m));
        i++;
    }

    return 0;
}
