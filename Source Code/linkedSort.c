#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    int data;
    struct listNode *link;
};

struct listNode *front = NULL, *rear = NULL;

struct listNode *create(int value)
{
    struct listNode *node;
    node = (struct listNode *)malloc(sizeof(struct listNode));
    node->data = value;
    node->link = NULL;
    return node;
}

void addElement(int val)
{
    struct listNode *node = create(val);
    if (front == NULL)
    {
        front = rear = node;
    }
    else
    {
        rear->link = node;
        rear = node;
    }
}

void sort()
{
    struct listNode *itt, *big;
    int temp;
    big = front;
    while (big != NULL)
    {
        itt = big->link;
        while (itt != NULL)
        {
            if (itt->data > big->data)
            {
                temp = itt->data;
                itt->data = big->data;
                big->data = temp;
            }
            itt = itt->link;
        }
        big = big->link;
    }
}

void display()
{
    struct listNode *temp = front;
    while (temp != NULL)
    {
        printf("%d--> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
}

void main()
{
    int data, N;
    printf("How many students in the list (N): ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        printf("Enter the mark of stduent %d: ", i + 1);
        scanf("%d", &data);
        addElement(data);
    }
    printf("Current list: ");
    display();
    printf("\nSorting the list\n");
    sort();
    printf("List after sorting: ");
    display();
}