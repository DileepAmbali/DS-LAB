#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct list_node *link;

} list_node;

list_node *first = NULL;

list_node *createNode(int value)
{
    list_node *node;
    node = (list_node *)malloc(sizeof(list_node));
    node->data = value;
    node->link = NULL;
    return node;
}

void insert(int value)
{
    list_node *node = createNode(value);
    if (first == NULL)
    {
        first = node;
        return;
    }
    else
    {
        list_node *temp = first;
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

    list_node *temp1 = NULL;
    list_node *temp2 = first;
    list_node *temp3 = NULL;

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
    list_node *temp = first;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    printList();
    reverse();
    printList();

    return 0;
}