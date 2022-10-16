// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     FILE *file1;
//     int num;
//     char filename[] = "file1.txt";
//     file1 = fopen(filename, "r");

//     if(file1 == NULL){
//         printf("Cannot open %s \n", filename);
//     }
//     else{
//         printf("The value of file1: %s", file1);
//         printf("Ready to close the file.");
//         fclose(file1);
//     }

//     return 0;

// }

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   int num;
   char str1[50];
   FILE *fptr;
 
   if ((fptr = fopen("file1.txt","r")) == NULL){
       printf("Error! opening file");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
 
   //fscanf(fptr,"%d", &num);
   //đọc file file1.txt và lưu vào cho biến str1 ở đây.
   fscanf(fptr, "%[^]", &str1);
 
   //printf("Value of n=%d", num);
   printf("String trong file la : %s", str1);
   fclose(fptr); 
  
   return 0;
}


 
// #include <stdio.h>
// #include <stdlib.h>  /* For exit() function */
// int main()
// {
//    char sentence[1000];
//    FILE *fptr;
 
//    fptr = fopen("file4.txt", "w");
//    if(fptr == NULL)
//    {
//       printf("Error!");
//       exit(1);
//    }
   
//    printf("Enter a sentence:\n");
//    gets(sentence);
 
//    fprintf(fptr,"%s", sentence);
//    fclose(fptr);
 
//    return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>


// int main(){
//     char str1[100];
//     FILE *p;

//     p = fopen("filemoi.txt", "r");
//     if(p == NULL){
//         printf("Error");
//         exit(1);
//     }

//     fscanf(p, "%[^\n]%*c", &str1);

//     printf("Chuoi duoc lay trong file filemoi.txt la : %s", str1);
//     fclose(p);
//     return 0;
// }