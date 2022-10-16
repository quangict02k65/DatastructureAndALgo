#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10000

#define ULL unsigned long long

typedef struct Node
{
    ULL key;
    struct Node *next;
} Node;

Node *T[M];


int h(ULL k)
{
    return k % M;
}

Node *makeNode(ULL v)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = v;
    p->next = NULL;
    return p;
}

Node *insertList(Node *head, ULL k)
{
    Node *newNode = makeNode(k);
    newNode->next = head;

    return newNode;
}

int findList(Node *head, ULL k)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->key == k)
            return 1; 
        p = p->next;
    }
    return 0;
}

int find(ULL k)
{
    int i = h(k);

    int result = findList(T[i], k);

    if (result == 0)
        return 0;
    return 1;
}

int insert(ULL k)
{
    int i = h(k);

    int result = findList(T[i], k);

    if (result == 1)
        return 0;
    else {
        T[i] = insertList(T[i], k);
    }
    return 1;
}


int main()
{
    for (int i = 0; i < M; i++)
    {
        T[i] = NULL;
    }
    ULL key;

        //Read the first block:
    char c[50];

    while(1){
        scanf("%s",c);

        if(strcmp(c,"*") == 0)
             break;
        ULL key = 0;
        for (int i = 0; i < strlen(c); i++)
            key = key*10 + (c[i] -'0');

        insert(key);
    }

    //Read second block:
    char cmd[50];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"***") == 0) 
            break;
        else if(strcmp(cmd,"find") == 0){
                ULL k; 
                scanf("%lld", &k);
                int ans = find(k);
                printf("%d\n", ans);
        }else if(strcmp(cmd, "insert") == 0){
            ULL k;
            scanf("%lld",&k);
            int ans = insert(k);
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
