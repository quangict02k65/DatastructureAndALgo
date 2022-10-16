#include<stdio.h>
#include<stdlib.h>

typedef struct{
    float item;
    struct StackNode *next;
} StackNode;

typedef struct{
    StackNode *top;
}Stack;

//stack inititalize
Stack* StackConstruct(){
    Stack *s;
    s = (Stack*)malloc(sizeof(Stack));
    if(s == NULL){
        return NULL;
    }
    s -> top = NULL;
    return s;
}

//check empty
int StackEmpty(Stack *s){
    return (s->top == NULL);
}

//pop stack
float StackPop(Stack *s){
    float data;
    StackNode *node;

    if(StackEmpty(s)){
        return 0;
    }

    node = s -> top;
    data = node -> item;
    s -> top = node -> next;
    free(node);

    return data;
}

//check stack full
int StackFull(){
    printf("\nNo memory! Stack is full");
    return 1;
}

//destroy stack
void StackDestroy(Stack *s){
    while(!StackEmpty(s)){
        StackPop(s);
    }
    free(s);
}

//display all items in the stack 
void disp(Stack* s){
    StackNode* node;
    int a = 0;
    float m;
    printf("\n\nList of all items in the stack \n\n");
    if(StackEmpty(s)){
        printf("\n\n Empty stack \n\n");
    }
    else{
        node = s->top;
        do{
            m = node->item;
            printf("%8.3f \n", m);
            node = node->next;
        }while(!(node == NULL));
    }
}


//push stack 
int StackPush(Stack* s, float item){
    StackNode *node;
    node = (StackNode*)malloc(sizeof(StackNode));

    if(node == NULL){
        StackFull();//overflow
        return 1;
    }
    node -> item  = item;
    node -> next = s -> top;
    s -> top = node;

    return 0;
}




int main(){
    int ch, n , i;
    float m = 0;
    Stack* stackPtr;

    while(1){
        printf("\n\n============================\n");
        printf("1.Create \n 2.Push \n 3.Pop \n 4.Display \n 5.Exit\n");
        printf("Input number to select the appropriate operator: ");
        scanf("%d", &ch);
        printf("\n\n");
    }

    switch(ch){
        case 1: 
            printf("init stack: ");
            stackPtr = StackConstruct();
            break;
        case 2:
            printf("Input float number to insert into stack : ");
            scanf("%f", &m);
            StackPush(stackPtr, m);
            break;
        case 3:
            m == StackPop(stackPtr);
            if(m != 0){
                printf("\n Data value of the popped node : %8.3f\n", m);
            }
            else{
                printf("\n empty stack, cann't pop \n");
            }
            break;
        case 4:
            disp(stackPtr);
            break;
        case 5:
            printf("\n BYe Bye \n\n");
            exit(0);
            break;
        default: 
            printf("Wrong choice\n\n");
    }
    return 0;
}