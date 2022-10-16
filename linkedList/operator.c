#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//traversing a singly linked list
// void traversing(){
//     for(cur = head; cur != NULL; cur = cur->next){
//         //show data of current node (cur->data)
//     }
// }

//a sequence of integers is stored by a singly linked list
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//inset a node into the singly linked list
//at the beginning of list
//after position pointed by the pointer cur
//before the position pointed by the pointer cur
//at the end of the list

//at the beginning of list
Node* insertHead(int data, Node* head){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;

    return head;
}

//insert new node after the position pointed by the pointer cur
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


//insert new node before the position by the pointer cur.
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

//insert at the end of list
Node* insertEnd(Node* head, int data){
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

//delete the first node of the linked list
Node* deleteFirst(Node* head){
    Node* del;
    del = (Node*)malloc(sizeof(Node));

    del = head;
    head = del->next;
    free(del);

    return head;
}


//DELETE NODE
//delete node pointed by the pointer del
Node* deleteNode(Node* head, Node* del){
    if(head == del){//delete the first node
        head = del->next;
        free(del);
    }
    else{
        Node* prev = head;
        while(prev->next != del)
            prev = prev->next;

        prev->next = del->next;
        free(del);
    }

    return head;
}


//delete the finish node in linked list
Node* deleteEnd(Node* head){
    Node* last, *prev;

    prev = (Node*)malloc(sizeof(Node));
    last = (Node*)malloc(sizeof(Node));

    prev = head;
    while(prev->next->next != NULL){
        prev = prev->next;
    }
    last = prev->next;

    deleteNode(head, last);

    prev->next = NULL;

    return head;
}


//delete all node in linked list
Node* deleteAll(Node *head){
    Node* del;
    del = (Node*)malloc(sizeof(Node));
    del = head;
    while(del!= NULL){
        head = head->next;
        free(del);
        del = head;
    }

    return head;
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

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head-> next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Node* last;
    // last = (Node*)malloc(sizeof(Node));
    // last = head;
    //  while(last->next != NULL){
    //      last = last->next;
    //  }

    //  printf("%d", last->data);

    // Node* cur;
    // for(cur = head; cur != NULL; cur = cur->next){
    //     printf("data = %d\n", cur->data);
    // }


    // head = insertHead(12, head);
    // printList(head);

    // second = insertAfter(23,second);
    // printList(head);

    // second = insertBefore(second, head, head, 4);
    // printList(head);

    // head = insertEnd(head, 5);
    // printList(head);

    // head = deleteFirst(head);
    // printList(head);

    // head = deleteNode(head, second);
    // printList(head);

    // head = deleteEnd(head);
    // printList(head);

    head = deleteAll(head);
    printList(head);

    return 0;
}