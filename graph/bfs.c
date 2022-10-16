#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 40
#include<stdbool.h>

//write the program to create a graph of n vertices using a  adjacency list.
typedef struct node{
    int vertex;
    struct node *next;
}node;

typedef struct queue{
    node* front ; 
    node* rear;
}queue;

//if program had a weighted graph.
// typedef struct node{
//     int vertex;
//     int weight;
//     struct node *next;
// }node;


queue* createQueue(){
    queue* q;
    q = (queue*)malloc(sizeof(queue));
    q -> front = q -> rear = NULL;
    
    return q;
}

node* createNode(int x){
    node* p;
    p = (node*)malloc(sizeof(node));

    if(p == NULL){
        exit(1);
    }
    p->vertex = x;
    p ->next = NULL;
}

void enqueue(queue* q, int val){
    node* newnode = createNode(val);
    if(q->front == NULL && q->rear == NULL){
        //make both front and rear points to the new node
        q->front = q->rear = newnode;
    }
    else{
        //add newnode in rear->next;
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

void dequeue(queue *q){
    node *temp ;
    if(q->front == NULL){
        printf("Queue is Empty. Unable to perform dequeue \n");
    }
    else{
        temp = q->front;
        q->front = q->front->next;
        if(q->front == NULL)
            q->rear = NULL;
        free(temp);
    }
}

bool isEmpty(queue* q) {
  if (q->front == NULL)
    return true;
  else
    return false;
}


void printList(){
    node* temp;

    while(temp){
        printf("%d", temp -> vertex);
        temp = temp -> next;
    }
    printf("NULL \n");
}
//this algorithm : 4 stdps: 
/*
1.start by putting any one of the graph's vertices at the back of a queue
2. take the front item of the queue and add it to the visited list
3.create a list of that vertex's adjacent nodes, add the ones which aren't in the visited list to the back 
of the queue
4. keep repeating steps 2 and 3 util the queue is empty.
*/

//write function to create graph.
void createGraph(node *Adj[], int no_of_nodes){
    node* newNode, *last;
    int i, j, n, val;

    for( i = 0; i < no_of_nodes; i++){
        last = NULL;
        printf("Enter number of neighbor of node  %d: ", i);
        scanf("%d", &n);
        for(j = 1; j <= n; j++){
            printf("Enter the neighbor %d of node %d: ", j, i);
            scanf("%d", &val);

            newNode = (node*)malloc(sizeof(node));
            newNode -> vertex = val;
            newNode -> next = NULL;
            if(Adj[i] == NULL){
                Adj[i] = newNode;
            }
            else{
                last -> next = newNode;
            }
            last = newNode;
        }
    }
}

//write function to display graph .
void displayGraph(node* Adj[], int no_of_nodes){
    node* ptr;
    int i;

    for(i = 0; i < no_of_nodes; i++){
        ptr = Adj[i];
        printf("\nThe neighbor of node %d are: ", i);
        while(ptr != NULL){
            printf("\t%d", ptr -> vertex);
            ptr = ptr -> next;
        }
    }
}

void bfs(node* Adj[], int u, int *visited){
    //put the start vertex in queue
    queue* q = createQueue();
    enqueue(q, u);
    visited[u]  =  true;
    while(!isEmpty(q)){
        printf("\t%d\t", u);
        node *p;
        p = Adj[u];
        while(p != NULL){
            if(visited[p->vertex] == false)
                enqueue(q, p->vertex);
            p = p->next;
        }
        dequeue(q);
        bfs(Adj, q->front->vertex, visited);
    }
}
    //take the front item , add visited array 

    //create list vertex adjacency of that vertex, add ones that aren't visited

    //repeat 2 and 3.

int main(){
    node *Adj[10];
    int i, no_of_nodes;
    bool visited[max];

    for(int i = 0 ;i < max; i++){
        visited[i] = false;
    }

    printf("\nEnter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);
    for(i = 0; i < no_of_nodes; i++){
        Adj[i] = NULL;
    }

    createGraph(Adj, no_of_nodes);
    printf("\n The graph is : \n");
    displayGraph(Adj, no_of_nodes);
        //deleteGraph(Adj, no_of_nodes);
    
    bfs(Adj, 0, visited);
    
    return 0;
}