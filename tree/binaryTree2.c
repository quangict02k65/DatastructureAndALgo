#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *leftchild;
    struct Node *rightchild;
}Node;

//find max of 2 number
int max(int a, int b){
    if(a >= b)
        return a;
    else return b;
}

//create a new node in tree
Node* makeTreeNode(int data){
    Node* newnode = NULL;
    newnode = (Node*)malloc(sizeof(Node));

//check allocattion is unsuccessful?
    if(newnode == NULL){
        printf("Out of memory \n");
        exit(1);
    }
    else{
        newnode -> data = data;
        newnode -> leftchild = NULL;
        newnode -> rightchild = NULL;
    }

    return newnode;
}

//insert node into a tree
Node *insertNode(Node* root, int data, bool checkleft){
    Node* newnode;
    Node* p;

    newnode = makeTreeNode(data);
    if(root = NULL)
        return newnode;
        //insert node on the leftmost of the tree
    if(checkleft == true){
        p = root;
        while(p -> leftchild != NULL)
            p = p -> leftchild;
            p ->  leftchild = newnode;
    }

    //insert on the right most of the tree.
    else{
        p = root;
        while(p -> rightchild != NULL){
            p = p -> rightchild;
            p -> rightchild = newnode;
        }
    }

    return root;
}

void insert(Node* root, int data, bool checkleft) {
   Node *tempNode = (Node*)malloc(sizeof(Node*));
   Node *current;
   Node *parent;

   tempNode->data = data;
   tempNode->leftchild = NULL;
   tempNode->rightchild = NULL;

   //if tree is empty
   if(root == NULL) {
       //if tree is null , the inserted node is root.
      root = tempNode;
   } 
   else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         //go to left of the tree
         if(checkleft) {
            current = current->leftchild;                
            
            //insert to the left
            if(current == NULL) {
               parent->leftchild = tempNode;
               return;
            }
         }  //go to right of the tree
         else {
            current = current->rightchild;

            //insert to the right
            if(current == NULL) {
               parent->rightchild = tempNode;
               return;
            }
         }
      }            
   }
}

//calculate depth of a tree.
int depth(Node* root){
    if(root == NULL)
        return 0;
    if(root -> leftchild == NULL && root -> rightchild == NULL)
        return 1;
    if(root -> leftchild == NULL)
        return depth(root -> rightchild) + 1;
    if(root -> rightchild == NULL)
        return depth(root -> leftchild) + 1;

    return max(depth(root -> leftchild), depth(root -> rightchild)) + 1; 
    
}

//the number of node in tree.
int countNodes(Node* root){
    if(root == NULL)
        return 0;
    else{
        int ld = countNodes(root -> leftchild);//count of left node
        int rd = countNodes(root -> rightchild);//count of right node
        return 1 + ld + rd;
    }
}

//free tree .
void freeTree(Node* root){
    if(root == NULL)
        return ;
    freeTree(root -> leftchild);
    freeTree(root -> rightchild);
    
    free(root);
}

int main(){
    Node* tree;
    tree = (Node*)malloc(sizeof(Node));
    int checkleft[] = {0,0,1,1,0};
    tree = makeTreeNode(0);
    printf("The number nodes of a tree is : %d", countNodes(tree));

    int n = 5;
    int* a ;
    a = (int *)malloc(n*sizeof(int ));

    for(int i = 0; i < n; i++){
        printf("Enter the number %d:  ", i+1);
        scanf("%d", &a[i]);
        insert(tree, a[i], checkleft[i]);
    }

    insert(tree->rightchild->rightchild, 67, 1);

    printf("THe depth of current tree is : %d\n", depth(tree));
    printf("The count node of current tree is : %d\n", countNodes(tree));

    printf("%d", tree->rightchild->rightchild->leftchild->data);

    // printf("The depth of current tree is : %d", depth(tree));
    // tree = insertNode(tree, 23, true);
    // tree = insertNode(tree, 32, false);

    // // printf("The number nodes of a tree is : %d", countNodes(tree));
    // printf("Value of current pointer tree is : %d\n", tree->data);

    // printf("The depth of current tree is : %d\n", depth(tree));

    // tree = insertNode(tree, 43, false);

    // printf("The depth of current tree is : %d", depth(tree));
    // // tree = insertNode(tree, 45, false);

    // // printf("value of root -> leftchild is : %d", tree->rightchild->data);
    // // //printf("THe number nodes of a current tree is : %d", countNodes(tree));




    return 0;
}