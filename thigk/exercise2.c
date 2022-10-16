#include<stdio.h>
#include<stdlib.h>
//check palindrome use linked list 

typedef struct Node{
    int data ;
    struct Node *next;
    struct Node* prev;
}Node;

Node *head, *tail;
Node* makeNode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL)
        exit(1);
    newnode -> data = data;
    newnode->prev = NULL;
    newnode -> next = NULL;
    return newnode;
}

void init(){
    head = NULL;
    tail = NULL;
}

int checkPalindrome2(Node* head, Node *tail){
    Node* cur; 
    for( cur = head; cur != NULL; cur = cur->next){
        if(cur->data != tail->data)
            return 0;
        else{
            // Node* prev = head;
            // prev->next = tail;
            // tail = prev;
            // while
            tail = tail->prev;
        }
    }
    return 1;
}

int checkPalindrome(Node* head, Node* tail){
    if(head->next == NULL ){
        return 1;
    }
    // for(Node* cur = head; cur->next != NULL; cur = cur->next){
    //     if(cur->data != last->data)
    //         return 0;
    //     else{
    //         Node* prev;
    //         prev->next = tail->next;
    //         head = head->next;
    //         last = last->prev;
    //     }
    // }
    else{
        if(head->data != tail->data){
            return 0;
        }
        else{
            // Node* prev;
            // prev->next = tail;
            // return checkPalindrome(head->next, tail->prev);
            Node* prev;
            prev->next = tail;
            head = head ->next;
            tail = tail->prev;
        }
    }
}

int main(){
    int number, i, element;

    scanf("%d", &number);
    init();
    
    for(i = 0; i < number; i++){
        scanf("%d", &element );
        Node* newnode = makeNode(element);
        if(head == NULL && tail == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            //tail->next = newnode;
            //tail = newnode;
            newnode->prev = tail; 
            tail->next = newnode;
            tail = newnode;
        }
    }
   printf("The value of function check is: %d \n", checkPalindrome2(head, tail));
//    for(Node* cur = head; cur != NULL; cur = cur->next){
//     printf("%d ", cur->data);
//    }

    return 0;
}