#include<stdio.h>

typedef struct StackNode{
    char data;
    struct StackNode *next;
} StackNode;

typedef struct{
    StackNode *top;
} Stack;

void init(Stack *s){
    s -> top = NULL;
}

int push(Stack *s, char new_data){
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode));
    if(node == NULL )
        printf("out of memory")
        return 0;
    
    node -> data = new_data;
    node ->next = s->top;
    s->top = node;
    return 1;
}

//xoa phan tu dau cua stack
char pop(Stack *s){
    char data;

    StackNode *node;
    if(isEmpty(*s))
        return NULL;

    node = s->top;
    data = node->data;
    s->top = node->next;
    free(node);
    
    return data;
}
int main(){
    printf("dfdf");
}