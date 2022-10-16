#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct Node
{
    int row, col;
    struct Node *next;
    struct Node *parent;
} Node;
Node *makeNode(int row, int col, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->next = NULL;
    node->parent = parent;
    return node;
}
Node *head, *tail;
int maze[max][max];
int n, m, r0, c0;
int visited[max][max];
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

void input()
{
    FILE *f = fopen("maze.txt", "r");
    fscanf(f, "%d%d%d%d", &n, &m, &r0, &c0);
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            fscanf(f, "%d", &maze[i][j]);
    }
    fclose(f);
}
void init()
{
    head = NULL;
    tail = NULL;
}
int isEmpty()
{
    return head == NULL && tail == NULL;
}
void push(Node *node)
{
    if (isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}
Node *pop()
{
    if (isEmpty())
        return NULL;
    Node *node = head;
    head = node->next;
    if (head == NULL)
        tail = NULL;
    return node;
}
int main()
{
    input();
    int r, c;
    for (r = 1; r <= n; r++)
    {
        for (c = 1; c <= m; c++)
            visited[r][c] = 0;
    }
    init();
    Node *startNode = makeNode(r0, c0, NULL);
    Node *finalNode;

    visited[r0][c0] = 1;
    init();
    push(startNode);
    while (!isEmpty())
    {
        Node *u = pop();
        int k;
        for (k = 0; k < 4; k++)
        {
            int nr = u->row + dr[k];
            int nc = u->col + dc[k];
            if (visited[nr][nc] == 0 && maze[nr][nc] == 0)
            {
                visited[nr][nc] = 1;
                Node *newnode = makeNode(nr, nc, u);
                if (nr == 0 || nr == n || nc == 0 || nc == m)
                {
                    finalNode = newnode;
                    break;
                }
                push(newnode);
            }
        }
        if (finalNode != NULL)
            break;
    }
    if (finalNode == NULL)
        printf("No solution out of the MAZE\n");
    else
    {
        printf("FOUND solution out of the maze: DONE");
        Node *cur = finalNode;
        while (cur != NULL)
        {
            printf("<---(%d,%d)", cur->row, cur->col);
            cur = cur->parent;
        }
    }
    return 0;
}