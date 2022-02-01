#include <stdio.h>

#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *first = NULL, *last = NULL, *temp = NULL;

void push()
{
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        temp->link = first;
        first = temp;
    }
}
void pop()
{
    if (first == NULL)
        printf("Stack is empty...underflow");
    else
        first = first->link;
}
void display()
{
    temp = first;
    while (temp != NULL)
    {
        printf(" %d---->", temp->data);
        temp = temp->link;
    }
    printf(" NULL");
}
void main()
{
    int ch;

    do
    {
        printf("\nMenu\n----\n1. Push\n2. Pop\n3.display\n4. Exit");
        printf("\nEnter the choice:");
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
            printf("There is no such operation:");
        }
    } while (1);
}