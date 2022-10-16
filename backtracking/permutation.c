#include<stdio.h>

#define max 100
int a[max], n, used[max];

void PrintSolution(){
    for ( int i = 1;i <= n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

int check(int y, int k){
    for(int i = 1; i <= k-1; i++){
        if(a[i] == y)
            return 0;
    }
    return 1;
}

// void Try(int k){
    //xác định các giá trị mà phần tử trong mảng có thể nhận 
//     for(int y = 1; y <= n; y++){
    //điều kiện của bài toán (các số phải khác nhau)
//         if(check (y, k)){
//             a[k] = y; gán vị trí thứ k cho y
 
//             if(k == n) nếu đủ số phần tử(duyệt hết mảng) thì in ra kết quả
//                 PrintSolution();

//             else Try(k+1); nếu không thì tiếp tục duyệt đến vị trí thứ k + 1.
//         }
           //nếu check = false thì quay trở lại try trước đó và tiếp tục làm việc với vòng lặp giá trị y tiếp theo.
//     }
// }


//cách 2 sử dụng mảng used để xác định trạng thái 
void Try(int k){
    for(int y = 1 ;  y <= n; y++){
        if(used[y] == 0){
            a[k] = y;
            used[y] = 1;
            if(k == n) PrintSolution();
            else
                Try(k+1);
            used[y] = 0;
        }
    }
}
int main(){
    n = 5;
    Try(1);

    for(int i = 1; i < n; i ++){
        used[i] = 0;
    }

    return 0;
}

