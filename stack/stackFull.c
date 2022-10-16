#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int item;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
}Stack;

int StackEmpty(const Stack *s) {
    return (s->top == NULL);
}

int StackPop(Stack *s) {
    int data;
    StackNode *node;
    if (StackEmpty(s))        //(1)
	   return 0; 	   // Empty Stack, can't pop
    node = s->top;             //(2)
    data = node->item;         //(3)
    s->top = node->next;       //(4)
    free(node);                //(5)
    return data;               //(6)
}

Stack *StackConstruct() {
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
	return NULL;  // No memory
    }
    s->top = NULL;
    return s;
}

/****   Destroy stack   *****/
void StackDestroy(Stack *s) {
    while (!StackEmpty(s)) {
	StackPop(s);
    }
    free(s);
}


/*** Check full  ***/
int StackFull() {
   printf("\n NO MEMORY! STACK IS FULL");  
    return 1;
}
void disp(Stack* s) {
   StackNode* node;
   int ct = 0; int m;
   printf("\n\n  List of all items in the stack \n\n");
   if (StackEmpty(s)) 
       printf("\n\n  >>>>>  EMPTY STACK   <<<<<\n");
   else {
      node = s->top;
      do {
	      m = node->item;  
         printf("%d \n", m); 
	      node = node->next;
       } while (!(node == NULL));
   }
}
int StackPush(Stack *s, int item) {
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode)); //(1)
    if (node == NULL) {
	StackFull(); return 1;  // overflow: out of memory
    }
    node->item = item;       //(1)
    node->next = s->top;     //(2)
    s->top = node;           //(3)
    return 0;
  }


int main() {
   int ch,n,i;   int m;
   Stack* stackPtr;
   while(1)
   {  printf("\n\n======================\n");
      printf("“ STACK TEST PROGRAM \n");
      printf("======================\n");
      printf(" 1.Create\n 2.Push\n 3.Pop\n 4.Display\n 5.Exit\n");
      printf("----------------------\n");
      printf("“Input number to select the appropriate operation: ");
      scanf("%d",&ch); printf("\n\n");
switch(ch) {
     case 1:    printf("“INIT STACK");
                stackPtr = StackConstruct(); break;
     case 2:    printf("“Input int number to insert into stack: ");
                scanf("%d",&m);
                StackPush(stackPtr, m); break; 
     case 3:    m=StackPop(stackPtr);
                if (m != 0)
                  printf("\n Data Value of the popped node: %d\n",m);
                else {
                  printf("\n  >>> Empty Stack, can't pop <<<\n");}  
                break;
     case 4:    disp(stackPtr); break;
     case 5:    printf("\n  Bye! Bye! \n\n"); 
                exit(0);    break;
     default:   printf("Wrong choice"); 
   } //switch
  } // end while
} //end main

