#include<stdio.h>
#include<stdlib.h>

//initials record of each node in linked list
typedef struct node{
    int data;
    struct node* next;
}node;



int main(){
    //create head node
    node *head;
    node *secondNode;
    node *thirdNode;

    secondNode = (node*)malloc(sizeof(node));
    head = (node*) malloc(sizeof(node));
    thirdNode = (node*)malloc(sizeof(node));
    thirdNode->data = 3;
    thirdNode->next = NULL;
    head->next = secondNode;

    head->data = 1;
    secondNode->data = 2;
    secondNode->next = thirdNode;
    printf("address head %8u addr head data %8u, addr head next %8u\n\n",head, &head->data, &head->next);
//address head 1140681376 addr head data 1140681376, addr head next 1140681384

    printf("dia chi : %8u", &secondNode->next);




    return 0;
}