#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct NodeT{
    int data;
    struct NodeT *leftChild;
    struct NodeT *rightChild;
}NodeT;

NodeT *root = NULL;

NodeT* makeNode(int newKey){
    NodeT * newnode = (NodeT*)malloc(sizeof(NodeT));
    newnode->data = newKey;
    newnode->leftChild = NULL;
    newnode->rightChild = NULL;

    return newnode;
}

NodeT* insert(NodeT* root, int data){
    if(root == NULL){
        root = makeNode(data);
    }
    if(root->data > data){
            root->leftChild = insert(root->leftChild, data);
        }
    else if(root->data < data) {
        root->rightChild = insert(root->rightChild, data);
    }
    
    return root;
}


void pre_order_traversal(NodeT* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

int main(){
    char str[20]; int number;
    
    while(strcmp(str, "#") !=  0){
        scanf("%s", str);
        if(strcmp(str, "insert") == 0){
            scanf("%d", &number);
            root = insert(root, number);
        }
    }
    pre_order_traversal(root);
    return 0; 
}