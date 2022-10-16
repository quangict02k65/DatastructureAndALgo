#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 20
#define M 10007


typedef struct TNode{
    char account[LEN];
    int count;
    int totalMoney;
    struct TNode* leftChild;
    struct TNode* rightChild;
}Node;

Node* makeNode(char* account, int count, int totalMoney){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->account,account);
    p->count = count;
    p->totalMoney = totalMoney;
    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}
Node* T[M];

int h(char* s){ //hash function for string
    int code = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        code = (code* 256 + s[i]) % M;
    }
    return code;
}
Node* findBST(char* key, Node* r){
    if(r == NULL) return NULL;
    int c = strcmp(key,r->account);
    if(c == 0) return r;
    if(c < 0) return findBST(key, r->leftChild);
    else return findBST(key, r->rightChild);
}
Node* insertBST(char* key, int count, int totalMoney, Node* r){
    if(r == NULL) return makeNode(key, count, totalMoney);
    int c = strcmp(key,r->account);
    if(c == 0) return r;
    if(c < 0) return insertBST(key, count, totalMoney, r->leftChild);
    else return insertBST(key, count, totalMoney, r->rightChild);
}
Node* find(char* k){
    int index = h(k);
    return findBST(k,T[index]);
}
void insert(char* key, int count, int totalMoney){
    int index = h(key);
    T[index] = insertBST(key, count, totalMoney, T[index]);
}

int checkAccount(char* s){
    if(strlen(s) < 6 && strlen(s) > 20) return 0;
    return 1;
}

int main(){
    char cmd[50];
    int totalNumberTrans = 0, totalMoney = 0;
    int checkaccount = 1;
    char fromAccount[LEN], toAccount[LEN];
    char money[LEN], timePoint[LEN], ATM[LEN];
    char fromDate[LEN], fromTime[LEN], toDate[LEN], toTime[LEN];
    int cnt = 0;
    while(1){
            //cnt++; if(cnt > 10) break;
        scanf("%s",&cmd);
        //printf("cmd = %s\n",cmd);
        if(strcmp(cmd,"#")==0) break;
        else{
            strcpy(fromAccount, cmd);
            scanf("%s",&toAccount);
            scanf("%s",&money);
            scanf("%s",&timePoint);
            scanf("%s",&ATM);
            totalNumberTrans ++;
            totalMoney += atoi(money); 
            if(checkAccount(fromAccount) == 0) checkaccount = 0;
            if(checkAccount(toAccount) == 0)  checkaccount = 0;
            Node* p = find(fromAccount);
            int sum;
            sum = atoi(money);
            if(p == NULL)
                {
                    insert(fromAccount,1,sum);
                }
            else{
                p->count = p->count + 1;
                p->totalMoney = p->totalMoney + sum;
            }
        }
    }
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"#")==0) break;
        else if(strcmp(cmd,"?total_money_transaction_from")==0){
            scanf("%s",fromAccount);
            Node* p = find(fromAccount);
            if(p == NULL)printf("%d\n",0);
            else printf("%d\n",p->totalMoney);
        }
    }
    return 0;
}
