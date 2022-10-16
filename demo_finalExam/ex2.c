#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
}Node;

Node* makeNode(int data){
        Node* newnode = (Node*)malloc(sizeof(Node));

        newnode->data = data;
        newnode->leftChild = NULL;
        newnode->rightChild = NULL;

        return newnode;
}

Node* insert(Node* root, int data){
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


void pre_order_traversal(Node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

//left right root
void post_order_traversal(Node* root) {
   if(root == NULL )
      return ;
   post_order_traversal(root->leftChild);
   post_order_traversal(root->rightChild);
   printf("%d ", root->data);
}

void cpy(char *ptr,char* str,int start,int len){
    for(int i = 0; i < len; i++){
        ptr[i] = str[start+i];
    }
    ptr[len] = '\0';
}



int main(){
    char input[256];

    Node* root = NULL;

    do{
        scanf("%s", input);
        //scanf("%[^\n]%*c", input);

        if(strcmp(input, "postorder") == 0){
            post_order_traversal(root);
            printf("\n");
        }
        if(strcmp(input, "preorder") == 0){
            pre_order_traversal(root);
            printf("\n");

        } 
        if(strcmp(input, "insert") == 0){
            int number;
            scanf("%d", &number);
            root = insert(root, number);
        }
    }

    while(strcmp(input, "#") != 0);

    return 0;
}