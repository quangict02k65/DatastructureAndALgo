#include<stdio.h>

int cnt = 0;
void hanoiTower(int n, char start, char end, char spare){
    if(n == 1){
        cnt++;
        printf("(%d) Move disk from tower %c to tower %c\n", cnt, start, end);
    }

    else{
        hanoiTower(n-1, start, spare, end);
        hanoiTower(1, start, end, spare);
        hanoiTower(n-1, spare, end, start);
    }
}

int main(){
    int n = 3; 

    hanoiTower(n, 'a', 'c', 'b');
    
    return 0;
}