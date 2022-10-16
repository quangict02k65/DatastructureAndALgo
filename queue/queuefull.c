#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct Queuenode{
    int col, row;
    struct Queuenode *next;
    struct Queuenode *parent;
}Node;

// typedef struct Queue{
//     Node *head;
//     Node *tail;
// }Queue;

Node* head, *tail;
Node* makeNode(int r, int c, Node* parent){
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = r;
    node->col = c;
    node->next = NULL;
    node->parent = parent;

    return node;
}

int maze[MAX][MAX];
int n, m, r0, c0;
int visited[MAX][MAX];

//tuong ung voi buoc di o tren ban co 
const int dr[4] = {1,-1,0,0};
const int dc[4] = {0,0,1,-1};

void input(){
    FILE* f = fopen("maze.txt", "r");
    fscanf(f, "%d%d%d%d", &n, &m, &r0, &c0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            fscanf(f, "%d", &maze[i][j]);
        }
    }
    fclose(f);
}

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    return head == NULL && tail == NULL;
}

//enqueue: add to position last of queue.
void push(Node *node){
    if(isEmpty()){
        head = node; 
        tail = node;
    }
    else{
        tail -> next = node; 
        tail = node;
    }
}

//dequeue: delete node that has position first of queue.
Node* pop()
{
    if (isEmpty())
        return NULL;
    Node* node = head;
    head = node->next;
    if (head == NULL)
        tail = NULL;
    return node;
}

//write function traversal bfs algorithm.




int main(){
    input();

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            visited[r][c] = 0;
        }
    }
    //create a start node .
    init();
    Node* startNode = makeNode(r0,c0,NULL);
    Node* finalNode = NULL ;
    visited[r0][c0] = 1;
    push(startNode);

    while(!isEmpty()){
        Node* u = pop();
        // for v in adjacency of u;
        for(int k = 0;  k < 4; k++){
            int nr = u->row + dr[k];
            int nc = u->col + dc[k];
            //if visited state is 0 and that position allow pass through then go there.
            if(visited[nr][nc] == 0 && maze[nr][nc] == 0 ){
                visited[nr][nc] = 1;
                Node* newnode = makeNode(nr,nc,u);
                if(nr == 0 || nr == n|| nc == 0 || nc == m){
                    finalNode = newnode;
                    break;
                }
                push(newnode);
            }
        }
        if(finalNode != NULL){
            break;
        }
    }
    printf("(%d, %d)", finalNode->row, finalNode->col);

    if(finalNode == NULL)
        printf("No solution out of the maze");
    else
    {
        printf("FOUND solution out of the maze\n");
        printf("Escape complete !!!!!!!");
        Node *cur = finalNode;
        while (cur != NULL)
        {
            printf("<---(%d,%d)", cur->row, cur->col);
            cur = cur->parent;
        }
    }

    return 0;
}

