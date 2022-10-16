#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  int v;
  struct node *child;
  struct node *sibling;
}Node;

Node *createNode(int v){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->v = v;
  newNode->child = newNode->sibling  = NULL;
  return newNode;
}


// Node *findNode(Node *root,int c){
//   if(!root) return NULL;
//   if(root->v == c){
//     return root;
//   }
//   Node *node = findNode(root->child,c);
//   if(!node) return findNode(root->sibling,c);
// }


Node* findNode(Node* root, int key){
    if (root == NULL) return NULL;
    if(root->v == key ) return root;
    Node* p = root->child;
    while (p != NULL){
        Node* q = findNode(p,key);
        if(q != NULL) return q;
        p = p->sibling;
    }
}

void insert(Node *root,int c,int p){
  Node *fN = findNode(root,p);
  Node *tC = fN->child;
  if(tC == NULL){
    fN->child = createNode(c);
  }
  else{
    while(tC->sibling){
      tC = tC->sibling;
    }
    tC->sibling = createNode(c);
  }
}

int countLeaf(Node* root, int u){
    Node* p = findNode(root, u);
    if(p -> child == NULL) return 1;
    int count = 0;
    Node* q = p->child;
    while(q != NULL){
        //if(q->child == NULL) count ++;
        count += countLeaf(root, q->v);
        q = q->sibling;
    }
    return count;
}

//count the number child of current node.
int countChildNode(Node* root ,Node* current){
    int count = 1;
    Node* p  = current->child;
    while(p != NULL){
        count++;
        p = p->sibling;
    }
    return count;
}

//dem va tra ve so nut co dung k nut con tren cay goc u .
int countKChildren(Node *root,int k, int u){
    Node* U = findNode(root, u);
    int cnt = 0;
    if(countChildNode(root, U) == k) {
        return 1;
    }
    Node * q = U->child;
    while(q != NULL){
        cnt += countKChildren(root, k, q->v);
        q = q->sibling;
    }
    return cnt;
}

int main(){
  Node *root;
  char str[256];
  int c,p;
  scanf("%s",str);
  while(strcmp(str,"*") != 0){
    if(strcmp(str,"MakeRoot") == 0){
      scanf("%d",&c);
      root = createNode(c);
    }
    else if(strcmp(str,"Insert") == 0){
      scanf("%d",&c);
      scanf("%d",&p);
      insert(root,c,p);
    }
    else if(strcmp(str,"CountLeaves") == 0){
      scanf("%d",&c);
      printf("%d\n",countLeaf(root,c));
    }
    else if (strcmp(str,"CountKChildren") == 0){
      scanf("%d",&c);
      scanf("%d",&p);
      printf("%d\n",countKChildren(root,p,c));
    }
    else if(strcmp(str, "CountChild") == 0){
      scanf("%d", &c);
      printf("so phan tu con cua %d la %d \n", c, countChildNode(root, createNode(c)));
    }
    scanf("%s",str);
  }
}