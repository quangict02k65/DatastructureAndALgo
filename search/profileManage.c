#include<stdio.h>
#include<string.h>

#define MAXLEN 256
#define max 100

typedef struct Profile{
    char name[MAXLEN];
    char email[MAXLEN];
} Profile;

int n = 0;

Profile students[max];

void Insert(char* name, char* email){
    int i = n-1;
    while(i >= 0){
        int c = strcmp(students[i].name, name);
        if(c == 0){
            printf("Name %s exist , do not insert \n", name);
            return ;
        }
        else if ( c > 0){
            students[i+1] = students[i];
            i--;
        }
        else break;
    }
    strcpy(students[i].name, name);
    strcpy(students[i].email, email);
}

void Load(){
    char filename[256];
    printf("Enter name of file to read : ");
    scanf("%s", filename);
    FILE * f = fopen(filename, "r");
    if( f == NULL)
        printf("load data -> file not found \n");
    n = 0;
    while(!feof(f)){
        char name[256], email[256];

        fscanf(f, "%s", name, email);
        Insert(name, email);
    }
    fclose(f);
}

int BinarySearch(int low, int high, char*name){
    if(low > high) return -1;
    if(low == high){
        if(strcmp(students[low].name, name) == 0)
            return low;
        else return -1;
    }
    int m = (low+high)/2;
    int c = strcmp(students[m].name, name);
    if(c == 0) return m;
    if(c < 0) return BinarySearch(m+1, high, name);
    return BinarySearch(low, m-1, name);
}

void Find(){
    char name[256];

    printf("Enter name of student you want to find : ");
    scanf("%s", name);

    int indx = BinarySearch(0, n-1, name);
    if(indx == -1)
         printf("Not found student %s \n", name);
    else{
        printf("Found student %s, at position %d, email %s", students[indx].name, indx, students[indx].email);
    }
}

void RemoveStudent(){
    char name[256];

    printf("Enter name of student you want to remove : ");
    scanf("%s", name);

    int indx = BinarySearch(0, n-1, name);
    if(indx == -1){
        printf("Not found student with name %s", name);
    }
    else{
        for(int i = indx; i < n-1; i++){
            students[i] = students[i+1];
            n--;
        }
    }
}

void Store(){
    char filename[256];
    printf("Enter name of file to store: ");
    scanf("%s", filename);

    FILE *f = fopen(filename, "w");
    for(int i = 0; i < n; i++){
        fprintf(f, "%s %s", students[i].name, students[i].email);
        if(i < n-1)
            fprintf(f, "\n");
    }
    fclose(f);
}

void PrintList(){
    for(int i = 0; i < n; i++){
        printf("Student[%d] :  %s, %s", i, students[i].name, students[i].email);
    }
}

int main(){
    while(1){
        char cmd[256];

        printf("Enter command: ");
        scanf("%s", cmd);

        if(strcmp(cmd, "Quit" )== 0) break;
        if(strcmp(cmd, "Load") == 0) Load();
        if(strcmp(cmd, "Print") == 0) PrintList();
        if(strcmp(cmd, "Find" )== 0) Find();
        if(strcmp(cmd, "Insert") == 0){
            char name[256], email[256];
            printf("Enter name you want insert : "); 
            scanf("%[^\n]%*c", name);
            printf("Enter email you want insert : "); 
            scanf("%[^\n]%*c", email);

            Insert(name, email);
        };
        if(strcmp(cmd, "Remove") == 0) RemoveStudent();
        if(strcmp(cmd, "Store" )== 0) Store();

    }

    return 0;
}