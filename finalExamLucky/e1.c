#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 100
#define m 10007

typedef struct bank{
    //we will choose telephone number from for key of hash table.
    char AccFrom[20]; char AccTo[20];
    int Monney;
    char Time[20]; char Atm[10];
    struct bank *next;
}Bank;

//process collision by chaining with linked list for each hash index.
Bank *T[m];

Bank* makeBank(char *accfrom, char *accto, int money, char *atm, char *time){
    Bank* newbank = (Bank*)malloc(sizeof(Bank));
    strcpy(newbank->AccFrom, accfrom);
    strcpy(newbank->AccTo, accto);
    strcpy(newbank->Time, time);
    strcpy(newbank->Atm, atm);
    newbank->Monney = money;

    return newbank;
}

//convert from telephone number to hash value.
// int h(char *str){
//     int len = strlen(str);
//     long value = 0;
//     for(int i = 0; i < len; i++){
//         value += 10*value + (str[i] - '0');
//     }
//     return value % m;
// }

//hash function of teacher.
int h(char* s){ //hash function for string
    int code = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        code = (code* 256 + s[i]) % m;
    }
    return code;
}

// int findList(Call *head, char* callfrom)
// {
//     Call *p = head;
//     while (p != NULL)
//     {
//         if (strcmp(p->callFrom, callfrom) == 0)
//             return 1; 
//         p = p->next;
//     }
//     return 0;
// }

// int find(char* callfrom)
// {
//     int i = h(callfrom);

//     int result = findList(T[i], callfrom);

//     if (result == 0)
//         return 0;
//     return 1;
// }

Bank *insertList(Bank *head, char* accfrom, char* accto,char *time, char* atm, int money)
{
    Bank* newbank = makeBank(accfrom, accto, money, atm, time);
    newbank->next = head;

    return newbank;
}

Bank* insert(char *accfrom, char* accto, char *time, char* atm, int money)
{
    int i = h(accfrom);
    
    T[i] = insertList(T[i],accfrom, accto, time, atm, money);

    return T[i];
}

// int totalMoney(char *accfrom){
//     int total = 0;
//     int i = h(accfrom);
//     Bank* p = T[i];

// }


// //calculate duration time of two string time.
// int durationTime(char *str1, char *str2){
//     char hour[max], minutes[max], second[max];
//     int time[2];
//     char *str;

//       str = strtok(str1,":");
//       strcpy(hour,str);
//       str = strtok (NULL, ":");
//       strcpy(minutes,str);
//       str = strtok (NULL, ":");
//       strcpy(second,str);
//       time[0] = atoi(hour)*3600*24 + atoi(minutes)*60 + atoi(second);

//       str = strtok(str2,":");
//       strcpy(hour,str);
//       str = strtok (NULL, ":");
//       strcpy(minutes,str);
//       str = strtok (NULL, ":");
//       strcpy(second,str);

//       time[1] = atoi(hour)*24*3600 + atoi(minutes)*60 + atoi(second);

//       return (time[1] - time[0]);
// }
// int totalDuration(char *callfrom){
//     int total = 0;
//     int i = h(callfrom);

//     Call* p = T[i];
//     while(p != NULL){
//         if(strcmp(p->callFrom, callfrom) == 0){
//             total += durationTime(p->fromH, p->toH);
//         }
//         p = p->next;
//     }

//   return total;
// }

// int checkCorrectPhone(char *telNumber){
//     if(strlen(telNumber) != 10) return 0;
//     for(int i = 0; i < strlen(telNumber); i++){
//         if(telNumber[i] < 48 || telNumber[i] > 57){
//             return 0;
//         }
//     }
//     return 1;
// }



int main(){
    int  numberTransac = 0;
    int money;
    char f[100];
    char accfrom[100], accto[100], time[100], atm[100];

    for (int i = 0; i < m; i++)
    {
        T[i] = NULL;
    }
  
//   do{
//     scanf
//     scanf("%s%s%d%s%s",accfrom,accto,money, time, atm);
//     if(strcmp(accfrom,"#") == 0) break;
//     int k = h(accfrom);
//     T[k] = insert(accfrom, accto , time, atm, money);
//     numberTransac ++;
//   }
//   while(1);
  while(1){
    scanf("%s",accfrom);
    if(strcmp(accfrom,"#") == 0) break;
    scanf("%s",accto);
    scanf("%d", &money);
    getchar();
    scanf("%s%s", time, atm);
    int k = h(accfrom);
    T[k] = insert(accfrom, accto, time, atm, money);
    numberTransac++;
  }

  do{
    scanf("%s",f);
    if(strcmp(f,"#") == 0) break;
    if(strcmp(f,"?number_transactions") == 0){
        printf("%d\n", numberTransac);
    }
    // else if(strcmp(f,"?number_calls_from") == 0){
    //     char p[100];
    //     scanf("%s",p);
    //     printf("%d\n",countFrom(p));
    // }
    // else if(strcmp(f,"?number_total_calls") == 0)
    //     printf("%d\n",count);
    // else if(strcmp(f,"?count_time_calls_from") == 0){
    //     char p[100];
    //     scanf("%s",p);
    //     printf("%d\n",totalDuration(p));
    // }
  }
  while(1);
}