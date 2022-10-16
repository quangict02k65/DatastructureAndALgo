#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node* leftMostChild; // pointer to the left-most child
    struct Node* rightSibling;// pointer to the right sibling}Node;
}Node;

Node *root = NULL;

Node *makeNode(int newkey){
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = newkey;
    p->leftMostChild = p->rightSibling = NULL;
    return p;
}

Node* makeRoot(int keyRoot){
    root = makeNode(keyRoot);
    return root;
}

Node* find(Node* root, int key){
    if (root == NULL) return NULL;
    if(root->key == key ) return root;
    Node* p = root->leftMostChild;
    while (p != NULL){
        Node* q = find(p,key);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
}


void insertUV(Node* root, int nodeU, int nodeV){
    Node* nodeU = makeNode(nodeU);
    //find node has value of nodeV
    Node* p = find(root,nodeV);
    if(p == NULL) return;
    Node *childp = p->leftMostChild;
    while (childp->rightSibling != NULL){
        childp = childp->rightSibling;
    }

    childp->rightSibling = nodeU;
}

//return the number of leaaves of tree has root = u.
int countLeavesU(Node* root, Node* u){
    Node* p = find(root, u->key);
    if(u == root){
        return 1;
    }
    int count = 1;
    Node* q = p->leftMostChild;
    if(q == NULL){
        count += countLeavesU(q);
        q = q->rightSibling;
    }
    return count;
}

// int countKChildren()
int main(){
    Node *root;
    char str[256];
    int c,p;
    scanf("%s",str);
    while(strcmp(str,"*") != 0){
        if(strcmp(str,"MakeRoot") == 0){
        scanf("%d",&c);
        root = makeNode(c);
        }
        else if(strcmp(str,"Insert") == 0){
        scanf("%d",&c);
        scanf("%d",&p);
        insertUV(root,c,p);
        }
        else if(strcmp(str,"CountLeaves") == 0){
        scanf("%d",&c);
        printf("%d\n",countLeavesU(root,c));
        }
        // else if (strcmp(str,"CountKChildren") == 0){
        // scanf("%d",&c);
        // scanf("%d",&p);
        // printf("%d\n",countKChildren(root,c,p));
        // }
        // else if(strcmp(str,"Count") == 0){
        // printf("%d\n",count(root));
        // }
        scanf("%s",str);
    }
    return 0;
}