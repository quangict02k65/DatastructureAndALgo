#include<stdio.h>

int main(){
    FILE *fp;
    int len;

    fp = fopen("vidu.txt", "w+");
    fputs("Vi du ham fseek dich chuyen con tro !!", fp);
    fseek(fp, 3, SEEK_SET);//chuyen vi tri den ki tu "d"

    fputs("sao su dung : ", fp);
    fclose(fp);

    len = ftell(fp);
    //ftell đưa ra vị trí hiện thời của con trỏ file 
    //ftell()
    

    //rewind(fp) đưa con trỏ file về đầu file 
    printf("The current position of pointer file is : %d", len );
    

    return 0;
}