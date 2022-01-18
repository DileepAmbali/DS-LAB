#include <stdio.h>
#include <stdlib.h>

struct list_node
{
    int data;
    struct list_node *link;
};

struct list_node *first = NULL;

struct list_node *createNode(int value)
{
    struct list_node *node;
    node = (struct list_node *)malloc(sizeof(struct list_node));
    node->data = value;
    node->link = NULL;
    return node;
}

void insert(int value)
{
    struct list_node *node = createNode(value);
    if (first == NULL)
    {
        first = node;
        return;
    }
    else
    {
        struct list_node *temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = node;
    }
}

void reverse()
{
    if (first == NULL)
    {
        printf("Linked list Empty!");
        return;
    }

    struct list_node *temp1 = NULL;
    struct list_node *temp2 = first;
    struct list_node *temp3 = NULL;

    while (temp2 != NULL)
    {
        temp3 = temp2->link;
        temp2->link = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    first = temp1;
}

void printList()
{
    struct list_node *temp = first;
    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf(" NULL");
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    printf("\nInitial Linked list");
    printList();
    printf("\n\nAfter reversal");
    reverse(); // Reversing the given linked list
    printList();

    return 0;
}