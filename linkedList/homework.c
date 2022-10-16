#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Profile{
    char id[20];
    float gradeM;
    float gradeC;
    float gradeP;
    float total;
    struct Profile* next;
}Profile;

Profile* first, *last;


Profile* makeStudent(char *id, float gradeM, float gradeC, float gradeP, float total){ 
    Profile* new_student;
    new_student = (Profile*)malloc(sizeof(Profile));

    strcpy(new_student->id, id);
    new_student->gradeM = gradeM;
    new_student->gradeC = gradeC;
    new_student->gradeP = gradeP;
    new_student->total = total;
    new_student->next = NULL;
    return new_student;

}
//insert at the last of list
void insertlast(char *id, float gradeM, float gradeC, float gradeP, float total){
    Profile* new_student = makeStudent(id, gradeM, gradeC, gradeP, total);
    if(first == NULL){
        first = new_student;
        last = new_student;
    }
    else{
        last->next = new_student;
        last = new_student;
    }
}

//printlist
void printList(){
    Profile* p = first; 
    while (p != NULL){ 
        printf("%s --  %.2f\t%.2f\t%.2f\t%.2f\n",p->id, p->gradeM, p->gradeC, p->gradeP, p->total);
        p = p->next;
    }
}

//load file
void loadFile(){
    char filename[100];
    printf("Enter the name of file: ");
    scanf("%s", filename);
    FILE* f = fopen(filename, "r");
    if(f == NULL)
        printf("Load data -> file not found\n"); 
    while(!feof(f)){
        //hàm này trả về true nêu đã đọc hết file(eof: end of file)
        char id[100];
        float gradeC, gradeM, gradeP, total;
        fscanf(f, "%s %f %f %f %f", id, &gradeM, &gradeC, &gradeP, &total);
        insertlast(id, gradeM, gradeC, gradeP, total );
    }
    fclose(f);
    printList();
}


//find student has id in list
void findStudent(){
    char id[20];
    printf("Enter the studentID that you want to find:");
    scanf("%s", id);
    Profile* found = NULL;
    for(Profile* cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->id, id) == 0){
            found = cur;
            break;
        }
    }
    if(found == NULL){
        printf("Not found profile with id %s\n", id);
    }
    else{
        printf("Found profile id = %s has gradeM = %f, gradeM = %f, gradeM = %f, gradeM = %f", found->id, found->gradeM, found->gradeC, found->gradeP, found->total );
    }
}

void removeProfile(){
    if(first == NULL){
        printf("The list is empty!!!");
        return;
    }
    char id[20];
    printf("Enter studentid that you want remove :");
    scanf("%s", id);
    Profile* cur = first, *prev = NULL;
    while(cur!= NULL){
        if(strcmp(cur->id, id) == 0){
            if(prev == NULL){
                //delete student at the first list
                first = cur->next;
                if(cur == last){
                    last = first;
                    //after deletion, the lsit consists only 1 student
                }
            }
            else{
                prev->next = cur->next;
                if(cur == last){
                    last = prev;
                }
            }
            free(cur);
        }
        prev = cur;
        cur = cur->next;
    }
}



void insert(){
    char id[20];
    float gradeC, gradeM, gradeP, total;
    printf("\nEnter id,gradeM, gradeC, gradeP, total : ");
    scanf("%s %f %f %f %f", id, &gradeM, &gradeC, &gradeP, &total);
    insertlast(id, gradeM, gradeC, gradeP, total);
}


void changeGrade(){
    char id[20];
    float new_gradeC, new_gradeM, new_gradeP, new_total;
    Profile* found = NULL;
    if(first == NULL){
        printf("The list is empty!!!");
        return ;
    }

    printf("Enter the studentID that you want to change grade: ");
    scanf("%s", id);
    for(Profile* cur = first; cur != NULL; cur = cur->next){
        if(strcmp(cur->id, id) == 0){
            found = cur;
            break;
        }
    }
    if(found == NULL){
        printf("Not found profile with id %s", id);
        return;
    }

    else{
        printf("\nEnter new gradeC, gradeM, gradeP, total: ");
        scanf("%f %f %f %f", &new_gradeM, &new_gradeC, &new_gradeP, &new_total );
        found->gradeC = new_gradeC;
        found->gradeM = new_gradeM;
        found->gradeP = new_gradeP;
        found->total = new_total;
    }
}


// void countStudentPass(){
//     int countPass = 0;

//     for(Profile*cur = first; cur != NULL; cur = cur->next){
//         if(cur->grade >= 5){
//             countPass++;
//         }
//     }

//     printf("There are %d students passing the Math course\n", countPass);
// }

//print information of all students getting maximum total grade 
void printMaxGrade(){
    Profile* student = NULL;
    Profile* max = NULL;
    max = first;
    //find the maximum total grade
    for(Profile* cur = first; cur != NULL; cur = cur->next){
        if(max->total < cur->total){
            max = cur;
        }
    }

void printStudent(Profile* cur){
    printf("Information: studentID = %s, gradeM = %f, gradeC = %f, gradeP = %f, total = %f", cur->gradeM, cur->gradeC, cur->gradeP, cur->total);
}

    //getting all student has maximum total grade
    for(Profile* cur = first; cur != NULL; cur = cur->next){
        if(cur->total == max->total){
            printStudent(cur);
        }
    }

}


float standardized(float grade){
    int gradeStan = (int)grade;
    if(gradeStan < grade < gradeStan+0.5){
        return gradeStan + 0.5;
    }
    if(gradeStan+0.5 < grade  < gradeStan +1){
        return gradeStan + 1;
    }
    else
        return grade;
}

//ask users enter a number and stored in variable k which is the number of students that HUST wants to 
//give the admission . Determine the minimal total grade that student need to archive to get the admission.
void Admission(){
    int K;
    float standardGrade;
    Profile* cur = NULL;
    printf("Enter the number of students that HUST wants to give the admission : ");
    scanf("%d", &K);

    //sort descending by total grade.
    for(Profile* i = first; i != NULL; i = i -> next){
        for(Profile* j = i-> next; j != NULL; j = j -> next){
            if(i->total < j->total){
                Profile* temp = i;
                j = j;
                j = temp;
            }
        }
    }

    //after be sorted,
    int loop = 1;
    cur = first; 
    while(loop <= K){
        standardGrade = cur->total;
        cur= cur->next;
    }

    standardGrade = standardized(standardGrade);

    printf("The minimal total grade that students need to archive to get the admissin is : %f\n", standardGrade);

}


int main(){
    first = NULL;
    last = NULL;

    loadFile();
    printList();

    findStudent();
    changeGrade();
    printList();

    Admission();

    return 0;
}