#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

//insert at the beginning: push1
Node* push1(int data, Node* head){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;

    return head;
}


//insert at the end of list:append1
Node* append1(Node* head, int data){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    }
    else{
        //find last node 
        Node* last;
        last = head;
        while(last->next != NULL){
            last = last->next;
        }

        last->next = new_node;
    }

    return head ;
}

//insert after the position pointed by pointer cur
Node* insertAfter(int data,Node*cur, Node* head){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if(head == NULL){
        head = new_node;
        cur = head;
    }
    else{
        new_node->next = cur->next;
        cur->next = new_node;
    }
    
    return new_node;
}


//insert before the position pointed by pointer cur
Node* insertBefore(Node* cur, Node* prev, Node* head,  int data){
    //initial previous node
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if(head == NULL){
        head = new_node;
        cur = head;
    }
    else if(cur == head){
        head = new_node;
        new_node->next = cur;
    }
    else{
        prev->next = new_node;
        new_node->next = cur;
    }

    return new_node;
}

//insert after the kth element in the list
Node *insertAfterItemk(Node* head, int k, int data){
    Node* nodek = NULL;
    Node* newnode = NULL;
    nodek = (Node*)malloc(sizeof(Node));
    newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;

    nodek = head;
    for(int i = 1; i < k; i++){
        nodek = nodek->next;
    }

    newnode->next = nodek->next;
    nodek->next = newnode;

    return newnode;
}

//display the list
void printList(Node* head){
    struct Node *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr -> next;
    }
    printf(" ]");
}

int main(){
    Node *head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* cur = NULL;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    cur = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head-> next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // head = push1(4, head);
    // printList(head);//[ 4 1 2 3  ]

    // head = append1(head, 5);
    // printList(head);//[ 1 2 3 5  ]
    // cur = second;
    // cur = insertBefore(cur,head, head, 34);
    // second = cur;
    // printList(head);//[ 1 34 2 3  ]

    //insert after node third.
    third = insertAfterItemk(head, 3, 12);
    printList(head);



}