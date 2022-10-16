#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100

typedef struct Profile{
    char *name;
    char firstName[max], middleName[max], lastName[max];
    int year, month, day;
    char dateOfBirth[max];
}profile;

void input(char *filename){
    char name[256];
    char dateOfBirth[256];
    int year, month, day;
    FILE* f = fopen(filename, "w");
    int i = 0;
    while(1){
        printf("Enter name of staff %d : ", i+1);
        gets(name);
        //fgets(pro[i].name, sizeof(pro[i].name) + 1, stdin);
        //scanf("%[^\n]%*c", pro[i].name);
        if(strcmp(name, "#") == 0){
            break;
        }
        year = 1999 + rand() % 5;
        month = rand()%12 + 1;
        day = rand() % 28 + 1;
        sprintf(dateOfBirth, "%d-%d%d-%d%d", year, month/10, month%10, day/10, day%10);
        printf("create random birthday : %s \n", dateOfBirth);
        fprintf(f, "%s \n", name);
        fprintf(f, "%s\n", dateOfBirth);
        i++;
        // n++;
    }
    fprintf(f, "#");
    fclose(f);
}

void write(profile pro[max], char *filename){
    int i = 0;
    FILE* f = fopen(filename, "r");
    if(f == NULL) printf("Error to open file \n");
    char temp[255];
    while(1){
        fscanf(f, "%s", temp);
        if(strcmp(temp, "#") == 0) break;
        else{
            strcpy(pro[i].lastName, temp);
            fscanf(f, "%s", temp); strcpy(pro[i].middleName, temp);
            fscanf(f, "%s", temp); strcpy(pro[i].firstName, temp);
            fscanf(f, "%s", temp);
            int a1 = temp[0] - '0'; int a2 = temp[1]-'0';
            int a3 = temp[2]-'0'; int a4 = temp[3] - '0';
            pro[i].year = a1*1000 + a2*100 + a3*10 +a4;
            a1 = temp[5] - '0'; a2 = temp[6] - '0';
            pro[i].month = a1*10+a2;
            a1 = temp[8] - '0'; a2 = temp[9] - '0';
            pro[i].day = a1*10+a2;
            printf("Full name is :  %s %s %s, Date of birth is : %d-%d-%d \n", pro[i].lastName, pro[i].middleName, pro[i].firstName, pro[i].year, pro[i].month, pro[i].day);
            i++;
        }
    }
}

//return > 0 is pro1>pro2 else return < 0.
int compareData(profile pro1, profile pro2){
    int r = strcmp(pro1.firstName, pro2.firstName);
    if(r == 0){
        int r1 = strcmp(pro1.middleName, pro2.middleName);
        if(r1 == 0){
            int r2 = strcmp(pro1.lastName, pro2.lastName);
            if(r2 == 0){
                if(pro1.year == pro2.year){
                    if(pro1.month == pro2.month){
                        {
                            if(pro1.day == pro2.day){
                                return 0;
                            }else return pro1.day > pro2.day ? 1 : -1;
                        }
                    }else pro1.month > pro2.month ? 1 : -1;
                }
                else pro1.year > pro2.year ? 1 : -1;
            }
            else return r2;
        }else return r1;
    } else return r;
}

void insertionSort(profile pro[max], int n){
    for(int k = 1; k < n; k++){
        int j;
        for(j = k - 1; j >= 0; j--){
            if(compareData(pro[j], pro[k]) > 0){
                break;
            }
        }
        profile temp = pro[k];
        for(int i = k; i >= j+2; i--){
            strcpy(pro[i].firstName,pro[i-1].firstName);
            strcpy(pro[i].middleName, pro[i-1].middleName); 
            strcpy(pro[i].lastName, pro[i-1].lastName); 
            pro[i].year = pro[i-1].year; 
            pro[i].month = pro[i-1].month; 
            pro[i].day = pro[i-1].day;
        }
        strcpy(pro[j+1].firstName,temp.firstName);
        strcpy(pro[j+1].middleName,temp.middleName); 
        strcpy(pro[j+1].lastName,temp.lastName); 
        pro[j+1].year = temp.year; 
        pro[j+1].month = temp.month; 
        pro[j+1].day = temp.day;
        //     arr[i] = arr[i-1];
        // arr[j+1] = temp;
    }
}

void assign(profile pro1, profile pro2){
    strcpy(pro1.lastName, pro2.lastName);
    strcpy(pro1.middleName, pro2.middleName);
    strcpy(pro1.firstName, pro2.firstName);
    pro1.year = pro2.year;
    pro1.month = pro2.month;
    pro1.day = pro2.day;
}
void swapProfile(profile pro1, profile pro2){
    profile temp;
    assign(temp, pro1);
    assign(pro1, pro2);
    assign(pro2,temp);
}

void selectionSort(profile pro[max], int n ){
    int i, j, indx;
    profile temp;

    for(i = 0; i < n-1; i++){
        indx = i;
        for(j = i+1; j < n; j++){
            if(compareData(pro[j], pro[indx]) < 0){
                indx = j;
            }
        }
        //swap(pro[index] vs pro[i])
        swapProfile(pro[indx], pro[i]);
    }
}

//bubble sort
void bubbleSort(profile pro[max], int n){
    int i, j;
    int sorted = 1;
    for(i = 0; i < n; i ++){
        for(j = 0; j < n-i-1; j++){
            if(compareData(pro[j], pro[j+1]) > 0){
                swapProfile(pro[j], pro[j+1]);
                sorted = 0;
            }
        }
        if(sorted == 1) return ;
    }
}
//merge sort.
void merge(profile pro[max], int l, int middle, int r ){
    profile tempPro[max];
    int id, id1, id2;

    id = 0; id1 = l; id2 = middle + 1;
    while(id1 <= middle && id2 <= r){
        if(compareData(pro[id1], pro[id2]) < 0){
            tempPro[id] = pro[id1];
            id1++;
            id++;
        }
        else{
            tempPro[id] = pro[id2];
            id2++;
            id++; 
        }
    }

    for(; id1 <= middle; id1++){
        tempPro[id] = pro[id1];
        id++;
    }
    for(; id2 <= r; id2++){
        tempPro[id] = pro[id2];
        id++;
    }
    
    for(int i = l, id = 0; i <= r; i++, id++){
        pro[i] = tempPro[id];
    }
}

void mergeSort(profile pro[max], int l, int r){
    if(l < r){
        int middle = (l+r)/2;
        mergeSort(pro, l, middle);
        mergeSort(pro, middle+1, r);
        merge(pro, l, middle, r);
    }
}

int main(){
    char filename[] = "profile-4.txt";
    profile pro[5];
    input(filename);
    write(pro, filename);

    bubbleSort(pro, 4);
    printf("after sorting by bubble sort  : \n");
    for(int i = 0; i < 4; i++){
        printf("Full name is :  %s %s %s, Date of birth is : %d-%d-%d \n", pro[i].lastName, pro[i].middleName, pro[i].firstName, pro[i].year, pro[i].month, pro[i].day);
    }
    return 0;
}