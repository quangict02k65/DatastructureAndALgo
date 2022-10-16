#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char name[256];
    struct Node* leftMostChild; // pointer to the left-most child
    struct Node* rightSibling;// pointer to the right sibling}Node;
}Node;

Node *root;

Node *makeNode(char *name){
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name,name);
    p->leftMostChild = p->rightSibling = NULL;
    return p;
}

Node* find(Node* root, char* name){
    if (root == NULL) return NULL;
    if (strcmp(root->name,name) == 0) return root;
    Node* p = root->leftMostChild;
    while (p != NULL){
        Node* q = find(p,name);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
}

void processFind(){
    char name[256];
    printf("Enter the name you want to find: ");
    scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL) printf("Not Found %s\n",name);
    else printf("Found %s\n",name);
}

void findChildren(){
    char name[256];    
    printf("Enter the name of parent node: "); 
    scanf("%s",name);Node* p = find(root,name);
    if(p == NULL) printf("Not Found %s\n",name);
    else {
        printf("List child of node %s: ",name);
        Node* q = p->leftMostChild;
        while(q != NULL){
            printf("%s ",q->name);
            q = q->rightSibling;
        }
    }
    printf("\n");
}

void addChild(char *nameP, char* nameC){
    Node* p = find(root,nameP);
    if(p == NULL) return;
    Node *childp = p->leftMostChild;
    while (childp->rightSibling != NULL)
        childp = childp->rightSibling;
    childp->rightSibling = makeNode(nameC);
}

void processAddChild(){
    char nameP[256], nameC[256];
    printf("Enter the name of parent node: ");
    scanf("%s",nameP);
    printf("Enter the name of child node: ");
    scanf("%s",nameC);
    addChild(nameP,nameC);
}

void printTree(Node* root)
{
    if (root == NULL) return;
    printf("%s: ",root->name);
    Node* p = root->leftMostChild;
    while (p != NULL){
        printf("%s ",p->name);
        p = p->rightSibling;
    }
    printf("\n");
    p = root->leftMostChild;
    while (p != NULL){
        printTree(p);
        p = p->rightSibling;
    } 
}

void printTreeF(Node* root, FILE* f)
{
    if (root == NULL) return;
    fprintf(f,"%s ",root->name);
    Node* p = root->leftMostChild;
    while(p != NULL){
        fprintf(f,"%s ",p->name);
        p = p->rightSibling;
    }
    fprintf(f," $\n");
    p = root->leftMostChild;
    while (p != NULL){
    printTreeF(p,f);
    p = p->rightSibling;
    } 
}

void processStore()
{
    char filename[256];
    printf("Enter the name of file: "); scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    printTreeF(root,f);
    fprintf(f,"$$");
    fclose(f);
}

int height(Node* p) //return height of the node pointed by p on the tree
{
    if (p == NULL) return 0;
    int maxH = 0;
    Node* q = p->leftMostChild;
    while (q != NULL){
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}
void processHeight()
{
    char name[256];
    printf("Enter the name of node you want to know the height: "); 
    scanf("%s",name);
    Node* p = find(root,name);
    if (p == NULL) printf("Not Found %s\n",name);
    else printf("Found node %s having height = %d\n",name,height(p));
}

int count(Node* r)//return the number of nodes in the tree with root node pointed by the pointer r
{
    if (r == NULL) return 0;
    int cnt = 1; //is root
    Node* q = r->leftMostChild;
    while(q != NULL){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}

void freeTree(Node* root){
    if (root == NULL) return;
    Node* p = root->leftMostChild;
    while (p != NULL){
        Node* sp = p->rightSibling;
        freeTree(p);p = sp;
    }
    printf("free node %s\n",root->name);
    free(root);
    root = NULL;
}

void load(FILE *f){
    char name[256];
    int count = 0;
    Node *tempNode;
    int toggle = 0;
    while(!feof(f)){
        fscanf(f,"%s",name);
        if(strcmp(name,"$$") == 0) {
            printf("Finish reading file\n");
            break;
        }
        else if(strcmp(name,"$") == 0) count = 0;
        else{
            count++;
            if(count == 1){
                tempNode = find(root,name);
                if(tempNode == NULL) tempNode = makeNode(name);
                if(toggle == 0) {
                    root = tempNode;
                    toggle = 1;
                }
            }
            else if(count == 2){
                tempNode->leftMostChild = find(root,name);
                if(tempNode->leftMostChild == NULL) tempNode->leftMostChild = makeNode(name);
                tempNode = tempNode->leftMostChild;
            }
            else{
                Node *tempNode2 = tempNode;
                while(tempNode2->rightSibling != NULL){
                    tempNode2 = tempNode2->rightSibling;
                }
                tempNode2->rightSibling = find(root,name);
                if(tempNode2->rightSibling == NULL) tempNode2->rightSibling = makeNode(name);
            }
        }
    }
}

int main(){
    while (1){
        char cmd[256], name[256];
        printf("Enter command: ");
        scanf("%s",cmd);
        if (strcmp(cmd,"Quit") == 0) break;
        else if (strcmp(cmd,"Load")==0) {
            char filename[256];
            printf("Enter the name of file: ");
            scanf("%s",filename);
            FILE* f = fopen(filename,"r");
            // Read file and create the tree
            root = NULL;
            load(f);
            fclose(f);

        }else if (strcmp(cmd,"Print")==0) printTree(root);
        else if (strcmp(cmd,"Find")==0) processFind();
        else if(strcmp(cmd,"FindChildren")==0) findChildren();
        else if(strcmp(cmd,"Height")==0) processHeight();else if(strcmp(cmd,"Count")==0) {
            printf("Number of members in the tree is %d\n",count(root));
        }else if(strcmp(cmd,"AddChild")==0) processAddChild();
        else if(strcmp(cmd,"Store")==0) processStore();
    }//end whilefreeTree(root);    }//end main
}