#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct stack{
    node* top;
    node* bottom;
}stack;


void stackInit(stack* s){
    s = (stack*)malloc(sizeof(stack));
    s->top = NULL;
}

int isEmpty(stack s){
    return s.top == NULL;
}

int push(stack* s, char new_data){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Out of memory \n");
        return 0;
    }
    newnode -> data = new_data;
    newnode -> next = s -> top;
    s->top = newnode;
    return 1;
}

char pop(stack* s){
    node* temp = (node*)malloc(sizeof(node));
    if(isEmpty(*s)){
        return NULL;
    }
    temp = s -> top;
    char data = temp -> data;
    s->top = temp -> next;
    free(temp);
    return data;
}

void Destroy(stack *s){
    while(!isEmpty(s)){
        StackPop(s);
    }
    free(s);
}

int checkParenthe(char *string){
    stack *s;
    stackInit(&s);
    for(int i = 0; i != "\0"; i++){
        if(string[i] == "{" || string[i] == "[" || string[i] == "("){
            push(&s, string[i]);
        }
        else{
            if(isEmpty(s)){
                return 0;
            }
            if(string[i] == "{" && s->top->data == "}")
                
            if(string[i] == "[" && s->top->data == "]")
                pop(&s);
            if(string[i] == "(" && s->top->data == ")")
                pop(&s);

        }
    }
    if(isEmpty(s))
        return 1;
    return 0;
}

int main(){
    stack* s;
    stackInit(s);
    char string[] = "{{}}{";
    printf("value of checkparenthe function is : %d", checkParenthe(string));
    return 0;
}