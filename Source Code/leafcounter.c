#include <stdio.h>
#include <stdlib.h>
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

void leafCounter(Node *r, int *cnt)
{
    if (!r->rchild && !r->lchild)
    {
        *cnt = *cnt + 1;
    }
    else if (!r->rchild)
    {
        leafCounter(r->lchild, cnt);
    }
    else if (!r->lchild)
    {
        leafCounter(r->rchild, cnt);
    }
    else
    {
        leafCounter(r->lchild, cnt);
        leafCounter(r->rchild, cnt);
    }
}

void main()
{
    int ch = -1, cnt = 0, data;
    while (ch != 0)
    {
        printf("\n\nBST Leaf Count ");
        printf("\n1)Insert ");
        printf("\n2)Count leaf: ");
        printf("\n0)QUIT ");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            insert(data, root);
            printf("\nInorder : ");
            inorder(root);
            break;
        case 2:
            cnt = 0;
            leafCounter(root, &cnt);
            printf("Leaves: %d", cnt);
            break;
        }
    }
}