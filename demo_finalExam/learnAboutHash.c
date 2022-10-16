#include<stdio.h>


/*
khi sử dụng hash func, khi ta có 100000 key mà sau khi hash function xong 
chỉ còn lại  1000 hash values. Do đó xảy ra hiện tượng trùng lắp (collision)
cách giải quyết : ví dụ hai đối tượng ra trùng một key, ta sử dụng 1 linked list hoặc array để lưu một 
dãy giá trị ở đó.

ứng dụng của hash table : 
1.hash set : Thường quản lý một tập các keys
ví dụ kiểm tra xem tên người đó có tồn tại hay chưa ,ta chỉ quan tâm đén key.

2. hash map: thường quản lý một cặp key-value.
ví dụ là quản lý số điện thoại dựa vào tên người( key : tên người , value : số điện thoại)
 ví dụ : đếm số hiện xuất hiện của các phần tử.

design a hash set : 
Bài toán : nhập vào n số x, tại mỗi thao tác kiểm tra xem x đã xuất hiện 
trước đó hay chưa .
nếu dùng list : 0(n)*m.
dùng mảng count : 0(1)*m.

bài toán trở nên rắc rối hơn nếu ta cho 0<=x<=10^9: ta nghĩ đến sử dụng hash table.
100000000 giá trị -----> hashfunction -> tập 1000 giá trị : y = x % 1000;
key     hashfucntion    hashvalue    bucket
1       1 % 1000        1               1
5000    5000%1000       0               5000
5001    5001%1000       1               1, 5001(xảy ra collision, nên ta sử dụng linked list nhập thêm vào )
10000   10000%1000      0               5000, 10000


hashset operation : 
hashfunction(int key) : chuyển từ key về hash value
add(int key) : thêm 1 key vào set
remove(int key) : xóa key trong set
contains(int key) : kiểm tra xem có key đó trong set hay không.

hashmap operation : 
hashfunction (int key )
put(int key, int value ): thêm một cặp key-value vào map
remove(int key) : xóa cặp key - value trong map
get(int key) : trả về value của phần tử có khóa key trong map
*/
#define size 1000

int hashFunction(int key){
    return key % size;
}

int add(int key){

}

int remove(int key){

}

int contains(int key){

}
int main(){

    return 0;
}