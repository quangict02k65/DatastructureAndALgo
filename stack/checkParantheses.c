#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Node{
    char data;
    struct Node *next;
} Node;

typedef struct Stack{
    Node* top;
    Node* bottom;
}Stack;

int isEmpty(Stack *s){
    if(s->top == NULL)
        return 1;

    return 0;
}

void initStack(Stack *s){
    s->top = s->bottom = NULL;
}

Node* createNode(char x){
    Node* p ;
    p = (Node*)malloc(sizeof(Node));

    if(p == NULL)
        exit(1);//tức là không cấp phát được bộ nhớ cho p .
    p -> data = x;
    p -> next = NULL;

    return p;

}

// char pop(Stack *s){
//     if(!isEmpty(s)){
//         Node* p ;
//         p = s->top; //lay top ra khoi stack
//         s->top = p->next;

//       //  return p->data;
//         free(p);
//     }
//     return 0;
// }

Stack* pop(Stack *s){
    if(!isEmpty(s)){
        Node* p = s->top; //lay top ra khoi stack
        s->top = p->next;
        free(p);
    }

    return s;
}


void push(Stack *s, char x){
    Node* p  = createNode(x);
    // if(p == NULL)
    //     return NULL;
    p->data = x;
    if(isEmpty(s))
        s->top = s->bottom = p;
    else{
        p->next = s->top; //chen vao dau cua stack
        s->top = p;//cap nhap head
    }
}


bool checkParentheses(char *expression){
    Stack* s ;
    s = (Stack*)malloc(sizeof(Stack));
    initStack(s);

    int i ;
    int size = strlen(expression);
    for(i = 0; i < size; i++){
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[' ){
            push(s, expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            if(isEmpty(s)){
                return false; 
            }
            if(s->top->data == '(' && expression[i] == ')'){
                pop(s);
            }
            else if(s->top->data == '[' && expression[i] == ']'){
                pop(s);
            }
            else if(s->top->data == '{' && expression[i] == '}'){
                pop(s);
            }
            else
                return false;
        }
        else
            return false;
    }
//after traversal all node of stack, if stack is empty then return true
    if(isEmpty(s)){
        return true;
    }
    else{
        return false;
    }
}

// void printOut(Stack *s){
//     if(!IsEmpty(s)){
//         Node* p = s->top;
//         while(p != NULL){
//             printf(" %c", p->data);
//             p = p->next;
//         }
//     }
// }

int main(){
    char exp[100];

     printf("Enter the expression that you want check: ");
     scanf("%s", exp);

     printf("The result: ");
     if(checkParentheses(exp)){
         printf("trueeeeeee\n");
     }
     else{
         printf("Falseeeeeee\n");
     }
    // Stack* s;
    // s = (Stack*)malloc(sizeof(Stack));

    // push(s, "c");
    // push(s, "n");
    // push(s, "d");

    // printOut(s);


    return 0;
}