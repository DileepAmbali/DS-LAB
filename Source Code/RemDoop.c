#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

Node *createNode(int data);
void createList(int data);
void deleteNode(Node *temp);
void remDoop();
void display();

void main()
{
    int data, n;
    printf("How many elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        createList(data);
    }
    printf("Linked list before removing duplicates: ");
    display();
    printf("Linked list after removing duplicates: ");
    remDoop();
    display();
}

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void createList(int data)
{
    Node *n = createNode(data);
    if (front == NULL)
    {
        front = n;
        rear = n;
    }
    else
    {
        rear->next = n;
        rear = rear->next;
    }
}

void deleteNode(Node *temp)
{
    if ((temp->next)->next != NULL)
        temp->next = (temp->next)->next;
}

void remDoop()
{
    Node *current, *temp, *trail;
    current = front;
    while (current)
    {
        if (!current->next)
        {
            break;
        }
        trail = current;
        temp = current->next;
        while (temp)
        {
            if (temp->data == current->data)
            {
                trail->next = temp->next;
                temp = trail->next;
            }
            else
            {
                trail = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}