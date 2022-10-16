#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *leftchild;
    struct node *sibling;
    char Acc[20];
}

Node* root = NULL;

Node *makeNode(char *acc){
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->Acc, acc);
    p->leftMostChild = p->rightSibling = NULL;
    return p;
}

Node* find(Node* root, char* acc){
    if (root == NULL) return NULL;
    //base case 
    if (strcmp(root->Acc, acc) == 0) return root;
    //implement recursively action .
    Node* p = root->left;
    while (p != NULL){
        Node* q = find(p,acc);
        if(q != NULL) return q;
        p = p->sibling;
    }
}

void addChild(char *accP, char* accC ){
    Node* p = find(root,accP);
    if(p == NULL) return;
    Node *childp = p->left;
    if(childp = NULL)
        p->left = makeNode(accC);
    while (childp->sibling != NULL)
        childp = childp->sibling;
    childp->sibling = makeNode(accC);
}

//compute the height of current node.
int height(Node* p) //return height of the node pointed by p on the tree
{
    if (p == NULL) return 0;
    int maxH = 0;
    Node* q = p->left;
    while (q != NULL){
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->sibling;
    }
    return maxH + 1;
}

int inspect(char *s1, char *s2, int n){
    if(find(root, s2) != NULL && height(makeNode(s1) == n-1)){
        return 1;
    }
    else addChild(s1,s2);
    return 0;
}


int main(){
    int totalMon = 0;
    int  numberTransac = 0;
    int money;
    char f[100];
    char acc1[20], acc2[20];

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
    scanf("%s",acc1);
    scanf("%s", acc2);

  }

  do{
    scanf("%s",f);
    if(strcmp(f,"#") == 0) break;
    if(strcmp(f,"?inspect_cycle") == 0){

    }
  }
  while(1);
}