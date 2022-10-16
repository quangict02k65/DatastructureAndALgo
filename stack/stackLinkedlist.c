#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Stack{
    Node* top;
    Node* bottom;
}Stack;

//initialize stack 
void Init(Stack *s){
  s->top = s->bottom = NULL;
}

//check stack empty?
bool IsEmpty(Stack* s){
    if(s->top == NULL)
        return true;

    return false;
}

Node* createNode(int x){
    Node* p ;
    p = (Node*)malloc(sizeof(Node));

    if(p == NULL)
        exit(1);//tức là không cấp phát được bộ nhớ cho p .
    p -> data = x;
    p -> next = NULL;

    return p;

}

void Push(Stack *s, int x){
    /*
    step 1: create node p
    step 2: stack is empty then head = tail = p
    step 3: else, insert p in the head of stack
    step 4: re assign top of stack.
    */


    Node* p  = createNode(x);

    if(IsEmpty(s))
        s->top = s->bottom = p;
    else{
        p->next = s->top; //chen vao dau cua stack
        s->top = p;//cap nhap head
    }
}

Stack* pop(Stack *s){
    /*
    step1:check if stack is empty?
    step2:create p pointed the node head(top)
    step 3: assign head equal p ->next
    step 4: freepointer p.
    */
    if(!IsEmpty(s)){
        Node* p = s->top; //lay top ra khoi stack
        s->top = p->next;
        free(p);
    }

    return s;
}

void printOut(Stack *s){
    if(!IsEmpty(s)){
        Node* p = s->top;
        while(p != NULL){
            printf(" %d", p->data);
            p = p->next;
        }
    }
}

void Input(Stack *s){
    int n; 
    printf("\nNhap so luong phan tu ban dau: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        Push(s,i);
    }
}

void menu(){
	Stack* s ;
    s = (Stack*)malloc(sizeof(Stack));

	Init(s);
	Input(s);
	printOut(s);
	int selection, k;


	do{
		printf("\n____Selection____\n1_Print out the current stack: .\n2_Push.\n3_Pop.\n0_Exit.\n4.print value of head : .\n Your choice : \n ");
		scanf("%d", &selection);

		switch(selection){
            case 0:{
                break;
            }
            case 1:{
                printOut(s);
                break;
            }
            case 2:{
                printf("\nEnter the number you want add to stack: ");
                scanf("%d", &k);
                Push(s, k);
                break;
            }
            case 3:{
                pop(s);
                break;
            }
            case 4:{
                printf("The value of the top pointer be pointed is  : %d", s->top->data);
                break;
            }
            default:{
                printf("wrong input! Please re-enter your choice: \n");
            }
		}
	} while(selection);
}

int main(){
	menu();
	return 0;
}