#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//write the program to create a graph of n vertices using a  adjacency list.
typedef struct node{
    char vertex;
    struct node *next;
}node;

//if program had a weighted graph.
// typedef struct node{
//     int vertex;
//     int weight;
//     struct node *next;
// }node;

node * gnode;

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

//write function to delete graph.
void deleteGraph(node* Adj[], int no_of_nodes){
    int i ;
    node * temp, *ptr;
    for(i = 0; i <= no_of_nodes; i++){
        ptr = Adj[i];
        while(ptr != NULL){
            temp = ptr;
            ptr = ptr -> next;
            free(temp);
        }
        Adj[i] = NULL;
    }
} 

int main(){
    node *Adj[10];
    int i, no_of_nodes;

    printf("\nEnter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);
    for(i = 0; i < no_of_nodes; i++){
        Adj[i] = NULL;
    }

    createGraph(Adj, no_of_nodes);
    printf("\n The graph is : \n");
    displayGraph(Adj, no_of_nodes);
        //deleteGraph(Adj, no_of_nodes);
    return 0;
}