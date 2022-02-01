#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL, *rear = NULL;

struct node *create(int data)
{
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->link = NULL;
    return node;
}

void push()
{
    int temp;
    printf("Enter data:");
    scanf("%d", &temp);
    struct node *node = create(temp);

    if (front == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->link = node;
        rear = node;
    }
}

void pop()
{
    if (front == NULL)
    {
        printf("\nNo items to pop!");
    }
    else
    {
        front = front->link;
    }
}

void display()
{
    if (front == NULL)
    {
        printf("\Queue is empty!\n");
        return;
    }
    struct node *temp;
    temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf(" %d--> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main()
{
    int ch;
    do
    {
        printf("QUEUE\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("ILLEGAL CHOICE");
        }
    } while (1);
}