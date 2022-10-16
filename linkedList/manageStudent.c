#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Profile{
    char id[20];
    char email[20];
    double grade;
    struct Profile *next;
}Profile;

Profile* first, *last;

Profile* makeProfile(char *id, char *email, double grade){
    Profile* newNode = (Profile*)malloc(sizeof(Profile));
    strcpy(newNode->id, id);
    strcpy(newNode->email, email);
    newNode->grade = grade;
    newNode->next = NULL;
    return newNode;
}

void insertLast(char *id, char* email, double grade){
    Profile* profile = makeProfile(id,email,grade);
    if (first == NULL){
        first = profile;
        last = profile;
    }
    else{
        last->next = profile; 
        last = profile;
    }
}

void loadFile(){
    char filename[50];
    printf("Enter the name of file: ");
    scanf("%s",filename);
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n"); 
    while(!feof(f)){
        char id[20], email[100]; 
        double grade;
        fscanf(f,"%s %s %lf",id, email, &grade);
        insertLast(id,email,grade);
    }
    fclose(f);
}

void printList(){
    Profile* p = first; 
    while (p != NULL){ 
        printf("%s: %s, %lf\n",p->id, p->email, p->grade);
        p = p->next;
    }
}

void findProfile(){
    char id[20];
    printf("Enter the studentID that you want to find: ");
    scanf("%s",id);
    Profile* found = NULL;
    for(Profile* cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->id,id)==0){
            found = cur;
            break;
        }
    }
    if(found == NULL) printf("NOT FOUND profile with id %s\n",id);
    else printf("FOUND profile id = %s has email = %s, grade = %lf\n",found->id,found->email, found->grade);
}

void removeProfile(){
    if (first == NULL){ 
        printf("The list is empty!!! ");
        return;
    }
    char id[20];
    printf("Enter the studentID that you want to find: ");
    scanf("%s",id);
    Profile *cur = first, *prev = NULL;
    while (cur != NULL){
        if (strcmp(cur->id,id) == 0){ //delete node cur
            if (prev == NULL){ //delete cur which is the first node:
                first = cur->next;
                if (cur == last) last = first; //after deletion, the list consists only 1 node                       
            }
            else{ //cur is not the first node:
            prev->next = cur->next;
            if (cur == last) last = prev;//cur is the last node
            }
            free(cur);
        }    
        prev = cur; 
        cur = cur->next;
    }
}

void storeFile(){
    char filename[256];
    printf("Enter the name of file: ");
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(Profile* temp = first; temp != NULL; temp = temp->next){
        fprintf(f,"%s %s %lf",temp->id,temp->email,temp->grade);
        if (temp->next != NULL) fprintf(f,"\n");
    }
    fclose(f);
}

void FREE_MEM(){
    Profile* del = first;
    while (del != NULL){
        Profile* first = first->next;
        free(del);
        del = first;
    }
}

void insert(){
    char id[20], email[100]; 
    double grade;
    printf("Enter studentID, email, grade:"); 
    scanf("%s%s%lf",id,email,&grade);
    insertLast(id,email,grade);
}

void changeGrade(){
    char id[20];
    double newGrade;
    Profile* found = NULL;
//check file empty
    if (first == NULL){ 
        printf("The list is empty!!! ");
        return;
    }

    printf("Enter the studentID that you want to change grade: ");
    scanf("%s",id);
    //duyet mang.
    for(Profile* cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->id, id) == 0){
            found = cur;
            break;
        }
    }

    if(found == NULL) 
        printf("NOT FOUND profile with id %s\n",id);
        
    else{
        printf("Enter new grade: ");
        scanf("%lf",&newGrade);
        found->grade = newGrade;
    }
}

void countStudentPass(){
    int countPass = 0;

    for(Profile*cur = first; cur != NULL; cur = cur->next){
        if(cur->grade >= 5){
            countPass++;
        }
    }

    printf("There are %d students passing the Math course\n", countPass);
}

int main(){
    first = NULL; 
    last=NULL;
    while(1){
        char cmd[256]; 
        printf("Enter command: "); 
        scanf("%s",cmd);
        if(strcmp(cmd,"Quit")==0) break;
        else if(strcmp(cmd,"Load")==0)   loadFile();
        else if(strcmp(cmd,"Print")==0)  printList();
        else if(strcmp(cmd,"Find")==0)   findProfile();
        else if(strcmp(cmd,"Insert")==0) insert();
        else if(strcmp(cmd,"Remove")==0) removeProfile();
        else if(strcmp(cmd,"Store")==0)  storeFile();
        else if(strcmp(cmd,"ChangeGrade")==0) changeGrade();
        else if(strcmp(cmd,"Pass")==0) countStudentPass();
    }
    FREE_MEM();
}