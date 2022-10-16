#include <stdio.h>
#include <stdlib.h>


typedef struct
{ char id[15];
  float maths, physics;
}student;

typedef struct
{ student data;
  struct ddlist* next;
  struct ddlist* prev;
}ddlist;

//Creating a doubly link list
int main() {
  ddlist* head;
  ddlist* tail;
  ddlist* second = NULL;
  ddlist* third = NULL;
	
	head = (ddlist*)malloc(sizeof(ddlist));
	second = (ddlist*)malloc(sizeof(ddlist));
	third = (ddlist*)malloc(sizeof(ddlist));

	strcpy(head->data.id,"Trong");
	head->data.maths = 12.1;
	head->data.physics = 15.3;
	head->prev = NULL;
	head->next = second;
	strcpy(second->data.id,"Lam");
	second->data.maths = 9.8;
	second->data.physics = 7.4;
	second->prev = head;
	second->next = third;
	strcpy(third->data.id,"Minh");
	third->data.maths = 8.3;
	third->data.physics = 18.5;
	third->prev = second;
	third->next = NULL;
	tail = third;

	printf("Address of nodes: head %8u second %8u third %8u\n",head,second,third);
	printf("\n");
	
	printf("Adresses of head %u and tail %u \n",head,tail);
	
	printf("\n");
		
	ddlist* current;
	for (current = head; current != NULL; current = current->next)
	  printf("id %s maths %2.1f physics %2.1f prev ptr %8u next ptr %8u \n",current->data.id,current->data.maths,current->data.physics,current->prev,current->next);
	/*
	printf("\n");
	printf("Addresses of the fields in the node\n");
	printf("\n");
	for (current = head; current != NULL; current = current->next)
	printf("Address data %8u address pointer %8u \n",&current->data,&current->next);*/
	return 0;
}