// ung dung cua Mono Link list
// dung dslk don tao stack.
#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *head;
	Node *tail;
}Stack;

void Init(Stack &s){
	s.head = s.tail = NULL;
}

bool isEmpty(Stack s){
	if(s.head == NULL ) return true;
	return false;
}

Node *creatNode(int x ){
	Node *p = new Node;
	if(p == NULL) exit(1); // do k dc cap phat bo nho
	p->data = x;
	p->next = NULL;
	return p;
}

void Push(Stack &s, int x ){
	Node *p = creatNode(x);
	if(isEmpty(s)) s.head = s.tail = p;
	else{
		p->next = s.head; // chan vao dau stack
		s.head = p; // cap nhat head
	}
}

int Pop(Stack &s ){
	if(!isEmpty(s)){
		Node *p = s.head; // lay top ra khoi stack
		s.head = s.head->next;
		return p->data;
		delete p;
	}
	return 0;
}

void xuat(Stack s){
	if(!isEmpty(s)){
		Node *p = s.head;
		while(p!=NULL){
			printf("%d", p->data)
			p = p->next;
		}
	}
}

void nhap(Stack &s ){
	int n; printf("\nNhap so luong ptu ban dau: "); scanf("%d", &n);
	for(int i = 1; i<= n; i++ ) Push(s,i);
}

void menu(){
	Stack s ;
	Init(s);
	nhap(s);
	xuat(s);
	int lc, k;
	do{
		printf("\n____LUA CHON____\n1_Xuat.\n2_Push.\n3_Pop.\n0_Exit.\n_Ban chon ? ");
		scanf("%d", &lc);
		switch(lc){
			case 0: break;
			case 1: xuat(s); break;
			case 2: printf("\nNhap k: "); scanf("%d", &k); Push(s,k); break;
			case 3: Pop(s); break;
			default: printf("\nNhap sai, nhap lai!");
		}
	} while(lc);
}

int main(){
	menu();
	return 0;
}