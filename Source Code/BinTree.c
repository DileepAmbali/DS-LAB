#include <stdio.h>
#include <stdlib.h>

Node *createNode(int value)
{
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{

    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

Node *insertLeft(Node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}

Node *insertRight(Node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}

int main()
{
    Node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    printf("Inorder traversal \n");
    inorder(root);
    printf("\nPreorder traversal \n");
    preorder(root);
    printf("\nPostorder traversal \n");
    postorder(root);
}