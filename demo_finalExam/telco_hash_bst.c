#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 100
#define m 10007

typedef struct call{
    //we will choose telephone number from for key of hash table.
    char callFrom[max];
    char fromH[max],toH[max];
    struct call* leftchild;
    struct call* rightchild;
}Call;

//process collision by chaining with linked list for each hash index.
Call *T[m];

Call *makeCall(char *callfrom, char* fromH,char *toH){
  Call *newCall = (Call*)malloc(sizeof(Call));

  strcpy(newCall->callFrom, callfrom);
  strcpy(newCall->fromH,fromH);
  strcpy(newCall->toH,toH);

  return newCall;
}

//hash function of teacher.
int h(char* s){ //hash function for string
    int code = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        code = (code* 256 + s[i]) % m;
    }
    return code;
}

Call* findBST(char* callfrom, Call* r){
    if(r == NULL) return NULL;
    int c = strcmp(callfrom,r->callFrom);
    if(c == 0) return r;
    if(c < 0) return findBST(callfrom, r->leftchild);
    else return findBST(key, r->rightchild);
}
Call* insertBST(Call* root, char* callfrom, char *fromH, char *toH){
    if(root == NULL) return makeCall(callfrom, fromH, toH);
    int c = strcmp(callfrom,r->callFrom);
    if(c == 0) return r;
    if(c < 0) return insertBST( r->leftchild, callfrom);
    else return insertBST( r->rightChild, callfrom);
}
Call* find(char* k){
    int index = h(k);
    return findBST(k,T[index]);
}
Call* insert(char *callfrom, char* fromH, char *toH){
    int index = h(key);
    T[index] = insertBST(T[index], callfrom);
    return T[index];
}

int countFrom(char *callfrom){
  int count = 0 ;
  int i = h(callfrom);
  Call* p = T[i];

  while(p != NULL){
    if(strcmp(p->callFrom, callfrom) == 0){
        count ++;
    }
    p = p ->next;
  }

  return count;
}

//calculate duration time of two string time.
int durationTime(char *str1, char *str2){
    char hour[max], minutes[max], second[max];
    int time[2];
    char *str;

      str = strtok(str1,":");
      strcpy(hour,str);
      str = strtok (NULL, ":");
      strcpy(minutes,str);
      str = strtok (NULL, ":");
      strcpy(second,str);
      time[0] = atoi(hour)*3600*24 + atoi(minutes)*60 + atoi(second);

      str = strtok(str2,":");
      strcpy(hour,str);
      str = strtok (NULL, ":");
      strcpy(minutes,str);
      str = strtok (NULL, ":");
      strcpy(second,str);

      time[1] = atoi(hour)*24*3600 + atoi(minutes)*60 + atoi(second);

      return (time[1] - time[0]);
}
int totalDuration(char *callfrom){
    int total = 0;
    int i = h(callfrom);

    Call* p = T[i];
    while(p != NULL){
        if(strcmp(p->callFrom, callfrom) == 0){
            total += durationTime(p->fromH, p->toH);
        }
        p = p->next;
    }

  return total;
}

int checkCorrectPhone(char *telNumber){
    if(strlen(telNumber) != 10) return 0;
    for(int i = 0; i < strlen(telNumber); i++){
        if(telNumber[i] < 48 || telNumber[i] > 57){
            return 0;
        }
    }
    return 1;
}



int main(){
    int checkCorrect = 1;
    int count=0;
    char f[100],from[100],toH[100],fromH[100];

    for (int i = 0; i < m; i++)
    {
        T[i] = NULL;
    }
  
  do{
    scanf("%s",f);

    if(strcmp(f,"#") == 0) break;
    scanf("%s%*s%*s%s%s",from,fromH,toH);
    checkCorrect = checkCorrectPhone(from);
    int k = h(from);
    T[k] = insert(from, fromH, toH);
    count++;
  }
  while(1);

  do{
    scanf("%s",f);

    if(strcmp(f,"#") == 0) break;
    if(strcmp(f,"?check_phone_number") == 0){
        printf("%d\n", checkCorrect);
    }
    else if(strcmp(f,"?number_calls_from") == 0){
        char p[100];
        scanf("%s",p);
        printf("%d\n",countFrom(p));
    }
    else if(strcmp(f,"?number_total_calls") == 0)
        printf("%d\n",count);
    else if(strcmp(f,"?count_time_calls_from") == 0){
        char p[100];
        scanf("%s",p);
        printf("%d\n",totalDuration(p));
    }
  }while(1);
}