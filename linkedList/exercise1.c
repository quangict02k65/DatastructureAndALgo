#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void push(Node** head_ref, int new_data); //insert beginning of list
void append(Node** head_ref, int new_data);//insert at the end of list
void printList(Node *node);

void printList(Node *node){
    Node *cur;
    for(cur = node; cur != NULL; cur = cur->next){
        printf("%d", cur->data);
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> next = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void append(Node*)
int main(){
    Node* head = NULL;// the beginning list is null
    int n = 0, data;
    int stop = 0;
    char Line[32];

    do{
        printf("Nhap so thu %d = ", n+1);
        fgets(Line, sizeof(Line), stdin);
        if(*Line == "\n") 
            stop = 1;
        else{
            data = atoi(Line);//atoi function to convert from string be pointed to integer.
            push(&head,data);
            n++;
        }
    } while (stop == 0);

    printf("Danh sach lien ket chua %d cac so nguyen vua nhap vao la : \n", n);
    printList(head);


    return 0;
}