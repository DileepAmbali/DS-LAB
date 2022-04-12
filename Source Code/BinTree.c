#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Node;

Node *root = NULL;

void insert()
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    printf("Enter data:- ");
    scanf("%d", &n->data);
    n->lchild = NULL;
    n->rchild = NULL;

    if (root == NULL)
        root = n;
    else
    {
        Node *pre, *cur;
        cur = root;
        while (1)
        {
            if (n->data < cur->data)
            {
                pre = cur;
                cur = cur->lchild;
                if (cur == NULL)
                {
                    pre->lchild = n;
                    break;
                }
            }
            else if (n->data > cur->data)
            {
                pre = cur;
                cur = cur->rchild;
                if (cur == NULL)
                {
                    pre->rchild = n;
                    break;
                }
            }
            else
            {
                printf("Invalid Input");
                exit(0);
            }
        }
    }
}

void search()
{
    int key;
    int f = 0;
    int nc = 0;
    printf("Enter key to serach:- ");
    scanf("%d", &key);
    Node *cur = root;

    while (cur != NULL)
    {
        nc++;
        if (cur->data == key)
        {
            f = 1;
            break;
        }

        if (key < cur->data)
            cur = cur->lchild;
        else if (key > cur->data)
            cur = cur->rchild;
    }
    if (f)
        printf("Key found, on level %d", nc);
    else
        printf("Key Not found.");
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
void preorder(Node *r)
{

    if (r != NULL)
    {

        printf("%d ", r->data);
        preorder(r->lchild);
        preorder(r->rchild);
    }
}
void postorder(Node *r)
{
    if (r != NULL)
    {
        postorder(r->lchild);
        postorder(r->rchild);
        printf("%d ", r->data);
    }
}

Node *childFinder(Node *r)
{
    Node *q = NULL;
    while (r->lchild != NULL)
    {
        q = r;
        r = r->lchild;
    }
    if (r->rchild != NULL)
        q->lchild = r->rchild;
    else
        q->lchild = NULL;
    return (r);
}

void delete ()
{
    printf("Enter key to delete: ");
    int d;
    scanf("%d", &d);
    Node *current = root;
    Node *Globalprev;
    Node *prevR;
    Node *prevL;
    int flag = 0;
    int save = 0;

    while (current != NULL)
    {
        if (current->data == d)
        {
            flag = 1;
            break;
        }

        if (d < current->data)
        {
            Globalprev = current;
            current = current->lchild;
        }
        else if (d > current->data)
        {
            Globalprev = current;
            current = current->rchild;
        }
    }
    if (flag == 0)
        printf("Key not found..!!!");
    else
    {
        if (current->lchild == NULL && current->rchild == NULL)
        {
            if (Globalprev->rchild == current)
                Globalprev->rchild = NULL;
            else if (Globalprev->lchild == current)
                Globalprev->lchild == NULL;
            free(current);
        }
        else if (current->rchild == NULL)
        {
            if (Globalprev->lchild == current)
                Globalprev->lchild == current->lchild;
            else if (Globalprev->rchild == current)
                Globalprev->rchild = current->lchild;
            free(current);
        }
        else if (current->lchild == NULL)
        {
            if (Globalprev->lchild == current)
                Globalprev->lchild == current->rchild;
            else if (Globalprev->rchild == current)
                Globalprev->rchild = current->rchild;
            free(current);
        }
        else
        {
            Node *in = current->rchild;
            if (in->lchild == NULL)
            {
                current->data = in->data;
                current->rchild = in->rchild;
            }
            else
            {
                in = childFinder(current->rchild);
                current->data = in->data;
            }
        }
    }
}

void main()
{
    int op;
    do
    {
        printf("\nBINARY SEARCH TREE\n");
        printf("1.Insert Element\n");
        printf("2.View in pre-order\n");
        printf("3.View in post-order\n");
        printf("4.View in in-order\n");
        printf("5.Delete an element\n");
        printf("6.Search for an element\n");
        printf("7.QUIT\n");
        printf("Enter your choice:- ");

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            delete ();
            break;
        case 6:
            search();
            break;
        }
    } while (op != 7);
}