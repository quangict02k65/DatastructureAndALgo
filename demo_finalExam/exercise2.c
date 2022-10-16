#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node_t;
typedef struct Command
{
    char st[102];
    int key;
} cm;
cm a[10000];
int LeftOf(int value, node_t *root)
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
    //    return value <= root->data;
}
int RightOf(int value, node_t *root)
{
    return value > root->data;
}
node_t *Insert(node_t *root, int value)
{
    if (root == NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->left == NULL;
        node->right == NULL;
        node->data = value;
        return node;
    }
    if (LeftOf(value, root))
        root->left = Insert(root->left, value);
    else if (RightOf(value, root))
        root->right = Insert(root->right, value);
    return root;
}
void PreOrder(node_t *root)
{
    if (root != NULL)
    {
        printf("%i ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(node_t *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%i ", root->data);
    }
}
int main()
{
    node_t *root = NULL;
    int n = 0;
    while (1)
    {
        scanf("%s", a[n].st);
        if (strcmp(a[n].st, "#") == 0)
            break;
        if (strcmp(a[n].st, "insert") == 0)
        {
            scanf("%i", &a[n].key);
        }
        n++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (strcmp(a[i].st, "insert") == 0)
    //         printf("%s %i\n", a[i].st, a[i].key);
    //     else
    //         printf("%s\n", a[i].st);
    // }
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].st, "insert") == 0)
        {
            int value = a[i].key;
            root = Insert(root, value);
        }
        if (strcmp(a[i].st, "preorder") == 0)
        {
            PreOrder(root);
            printf("\n");
        }
        if (strcmp(a[i].st, "postorder") == 0)
        {
            PostOrder(root);
            printf("\n");
        }
    }
    return 0;
}