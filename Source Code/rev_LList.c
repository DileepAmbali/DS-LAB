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

    struct list_node *prev = NULL;
    struct list_node *curr = first;
    struct list_node *next = NULL;

    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
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
    int n, ele;
    printf("Program to Reverse a Linked List\n");
    printf("How many elements in the list: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", &ele);
        insert(ele);
    }
    printf("\nInitial Linked list");
    printList();
    printf("\n\nAfter reversal");
    reverse();
    printList();

    return 0;
}