#include<stdio.h>
#include<stdlib.h>


//a doubly linked list contains an extra pointer, it is previous and next
//2 special nodes: tail and head
//head has pointer prev = null
//tail has pointer next = null


typedef struct{
    char id;
    struct ddlist* next;
    struct ddlist* prev;
}dllist;

dllist *head, *tail;




int main(){
    dllist* node1, *node2, *node3;

    node1 = (dllist*)malloc(sizeof(dllist));
    node2 = (dllist*)malloc(sizeof(dllist));
    node3 = (dllist*)malloc(sizeof(dllist));

    node1->data = "a";
    ndoe



    return 0;
}