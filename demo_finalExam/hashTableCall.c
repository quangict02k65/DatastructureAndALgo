#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct call{
  char from[100],fromH[100],toH[100];
  struct call *leftchild;
  struct call *rightchild;
}Call;

Call *makeCall(char *from,char* fromH,char *toH){
  Call *newCall = (Call*)malloc(sizeof(Call));

  strcpy(newCall->from,from);
  strcpy(newCall->fromH,fromH);
  strcpy(newCall->toH,toH);

  return newCall;
}

int checkFrom(Call *callArr[100],int i,char* p){
  int count=0;
  while(i > 0){
    if(strcmp(callArr[i-1]->from,p) == 0) count++;
    i--;
  }
  return count;
}

int checkDur(Call *callArr[10000], int i, char *p){
  char hour[10],minutes[10],second[10];
  int time[2];
  int sum=0;
  char *str;
  while(i>0){
    if(strcmp(callArr[i-1]->from, p) == 0){
      str = strtok(callArr[i-1]->fromH,":");
      strcpy(hour,str);
      str = strtok (NULL, ":");
      strcpy(minutes,str);
      str = strtok (NULL, ":");
      strcpy(second,str);

      time[0] = atoi(hour)*24*3600 + atoi(minutes)*60 + atoi(second);
      str = strtok(callArr[i-1]->toH,":");
      strcpy(hour,str);
      str = strtok (NULL, ":");
      strcpy(minutes,str);
      str = strtok (NULL, ":");
      strcpy(second,str);

      time[1] = atoi(hour)*24*60*60+atoi(minutes)*60+atoi(second);
      sum += time[1]-time[0];
    }
    i--;
  }

  return sum;
  
}

int checkNum(Call *callArr[10000],int i){
  while(i>0){
    if(strlen(callArr[i-1]->from) != 10) return 0;
    i--;
  }
  return 1;
}


int main(){
  Call* callArr[10000];
  int i=0;
  char f[100],from[100],toH[100],fromH[100];
  do{
    scanf("%s",f);
    if(strcmp(f,"#") == 0) break;
    scanf("%s%*s%*s%s%s",from,fromH,toH);
    callArr[i] = makeCall(from,fromH,toH);
    i++;
  }
  while(1);

  do{
    scanf("%s",f);
    if(strcmp(f,"#") == 0) break;
    if(strcmp(f,"?check_phone_number") == 0)
         printf("%d\n",checkNum(callArr,i));
    else if(strcmp(f,"?number_calls_from") == 0){
        char p[100];
        scanf("%s",p);
        printf("%d\n",checkFrom(callArr,i,p));
    }
    else if(strcmp(f,"?number_total_calls") == 0)
        printf("%d\n",i);
    else if(strcmp(f,"?count_time_calls_from") == 0){
        char p [100];
        scanf("%s",p);
        printf("%d\n",checkDur(callArr,i,p));
    }
  }while(1);
}