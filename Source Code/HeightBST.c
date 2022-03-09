#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;
Node *root = NULL;

Node *createNode(int data)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->lchild = NULL;
    n->rchild = NULL;
    return n;
}

void insert(int data, Node *r)
{
    if (!r)
    {
        root = createNode(data);
    }
    else
    {
        if (data > r->data)
            if (r->rchild == NULL)
                r->rchild = createNode(data);
            else
                insert(data, r->rchild);
        else if (data < r->data)
            if (r->lchild == NULL)
                r->lchild = createNode(data);
            else
                insert(data, r->lchild);
    }
}

void inorder(Node *r)
{

    if (r != NULL)
    {

        inorder(r->lchild);
        printf("%d ", r->data);
        inorder(r->rchild);
    }
}

void nodeCounter(Node *r, int *cnt)
{
    if (r != NULL)
    {

        nodeCounter(r->lchild, cnt);
        *cnt = *cnt + 1;
        nodeCounter(r->rchild, cnt);
    }
}

int heightOfBST(Node *r)
{
    if (r)
    {
        return MAX(heightOfBST(r->lchild), heightOfBST(r->rchild)) + 1;
    }
    return 0;
}

void main()
{
    int ch = -1, cnt = 0, data;
    while (ch != 0)
    {
        printf("\n\nBST ");
        printf("\n1)Insert ");
        printf("\n2)Node Counter ");
        printf("\n3)Edge Counter ");
        printf("\n4)Height Counter ");
        printf("\n0)QUIT ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            insert(data, root);
            printf("Inorder : ");
            inorder(root);
            break;
        case 2:
            cnt = 0;
            nodeCounter(root, &cnt);
            printf("Nodes: %d", cnt);
            break;
        case 3:
            cnt = 0;
            nodeCounter(root, &cnt);
            printf("Edges: %d", cnt - 1); // The number of edges is 1 less than the number of nodes in the tree
            break;
        case 4:
            cnt = 0;
            printf("Height: %d", heightOfBST(root));
            break;
        }
    }
}
