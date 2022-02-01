#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

struct node *create(int data)
{
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->link = NULL;
    return node;
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack is empty!\n");
        return;
    }
    struct node *temp;
    temp = top;
    printf("\n");
    while (temp != NULL)
    {
        printf(" %d --> ", temp->data);
        temp = temp->link;
    }
    printf(" NULL\n");
}

void push()
{
    int temp;
    printf("Enter data:");
    scanf("%d", &temp);
    struct node *node = create(temp);

    if (top == NULL)
    {
        top = node;
    }
    else
    {
        node->link = top;
        top = node;
    }
    display();
}

void pop()
{
    if (top == NULL)
    {
        printf("\nNo items deleted!");
    }
    else
    {
        top = top->link;
    }
    display();
}

void main()
{
    int ch;
    do
    {
        printf("\nStack\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
