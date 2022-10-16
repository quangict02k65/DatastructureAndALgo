#include<stdio.h>
#include<string.h>
#include<math.h>

#define max 256
#define LL long long 

// LL modEg(LL b, LL e,LL m){
//   LL res = 1,r = b % m;
//   while(e > 0){
//     if(e & 1){
//       res = (res * r) % m;
//     }
//     r = (r * r) % m ;
//     e >>= 1;
//   }
//   return res;
// }

LL hashFunction(char *str, int m){
    int leng = strlen(str);
    LL hashValue = 0,mod256 = 1;

    while(leng > 0){
      LL num = ((int) str[leng-1]) * mod256;
      hashValue += num % m;
      mod256 = ((mod256 % m) * (256 % m)) % m;
      leng--;
    }
    return hashValue % m;
}


int main(){
    LL n ;
    LL m;
    char str[max];
    LL i = 0;
    scanf("%lld %lld", &n, &m);

    while(i < n){
        scanf("%s[^\n]%*c", str);
        printf("%lld\n", hashFunction(str, m));
        i++;
    }

    return 0;
}