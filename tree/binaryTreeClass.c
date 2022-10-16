#include<stdio.h>

typedef struct Node{
    int id;
    struct Node* leftchild;
    struct Node* rightchild;
}Node;

Node* root;
Node* makeNode(int id){
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;
}

Node* find(Node* root, int id){
    if(root == NULL)
        return NULL;
    if(root->id == id)
        return root;
    Node* p = find(root->leftchild, id);
    if(p != NULL)
            return p;
    q = find(root->rightchild, id);
    return p;
}

void processFind(){
    int id; 
    printf("Enter the value you want to find : ");
    scanf("%d", &id);
    Node* p = find(root,id);
    if(p == NULL)
        printf("Not found %d \n", id);
    else
        printf("Found node %d :", id);
    printChildren(p);
}

void printChildren(Node* p ){
    if(p->leftchild == NULL)
        printf("Node %d does not has leftchild", p->id);
    else 
        printf("Node %d has left child is : %d", p->id, p->leftchild->id);
    if(p->rightchild == NULL)
        printf("Node %d does not has rightchild", p->id);
    else 
        printf("Node %d has right child is : %d", p->id, p->rightchild->id);
        
}


void addLeftChild(int cur_id, int child_id){
    Node* p = find(cur_id);
    if( p == NULL)
        printf("Not found node with %d", cur_id);
    if(p->leftchild != NULL)
        printf("Node %d has already leftchild", cur_id);
    p->leftchild = makeNode(child_id);
}

void addRightChild(int cur_id, int child_id){
    Node* p = find(cur_id);
    if( p == NULL)
        printf("Not found node with %d", cur_id);
    if(p->rightchild != NULL)
        printf("Node %d has already rightchild", cur_id);
    p->rightchild = makeNode(child_id);
}

void processAddLeftChild(){
    int id, idC;
    printf("Enter values of node and its child node :  ");
    scanf("%d%d", &id, &idC);
    addLeftChild(id, idC);
}

processAddRightChild(){
    int id, idC;
    printf("Enter values of node and its child node :  ");
    scanf("%d%d", &id, &idC);
    addRightChild(id, idC);
}

void ProcessStore(){
    char filename[256];
    printf("Enter the name of file: ");
    scanf("%s", filename);
    FILE* f = fopen(filename, "w");

}


//traversal tree : preorder
void preOrder(Node* root){
    printf("%d", root->id);
    preOrder(root->leftchild);
    preOrder(root->rightchild);
}

//traversal by inorder 
void inOrder(Node* root){
    inOrder(root->leftchild);
    printf("%d", root->id);
    inOrder(root->rightchild);
}

//traversal by postorder
void postOrder(Node* root){
    postOrder(root->leftchild);
    postOrder(root->rightchild);
    printf("%d", root->id);
}



void print(Node* root){
    if(root == NULL) return ;
    else printChildren(root);
    printf("\n");
    print(root->leftchild);
    print(root->rightchild);
}

int count(Node* root){
    if(root == NULL) return 0;
    return 1 + count(root->leftchild) + count(root->rightchild);
}

void printLeaves(Node* root){
    if(root == NULL)
        return ;
    if(root->leftchild == NULL && root->rightchild == NULL){
        printf("%d", root->id);
    }
    printLeaves(root->leftchild);
    printLeaves(root->rightchild);

}

int height(Node* p ){
    //base case
    if(p == NULL) 
        return 0;
    int maxH = 0;
    int hL  = height(p->leftchild);
    if(maxH < hL)
        maxH = hL;
    int hR = height(p->rightchild);
    if(maxH < hR)
        maxH = hR;
    return maxH + 1;
}

void freeTree(Node* root){
    if(root == NULL)
        return ;
    freeTree(root->leftchild);
    freeTree(rot->rightchild);
    free(root);
    root = NULL;
}
void loadfile(char *filename){
    FILE* f = fopen(filename, "r");
    root = NULL;
    //doan code lay ra tu file 
}

void processFile(){
    char filename[256];
    printf("Enter the name of file you want to read :");
    scanf("%s", filename);
    load(filename);
}


int main(){
    
}