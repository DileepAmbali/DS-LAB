#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node
{
    int data;
    struct list_node *link;
};

struct list_node *last = NULL;

bool isEmpty()
{
    if (last == NULL)
        return true;
    else
        return false;
}

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
    if (last == NULL)
    {
        last = node;
        last->link = last;
        return;
    }
    else
    {
        printf("Insert at end(1) or at beginig(-1)?: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            node->link = last->link;
            last->link = node;
            last = node;
            printf("\nElement added at end!\n");
            break;

        case -1:
            node->link = last->link;
            last->link = node;
            printf("\nElement added at front!\n");
            break;
        default:
            printf("Illegal choice!");
            break;
        }
    }
}

void printList()
{
    if (isEmpty())
    {
        printf("\nList Empty\n");
        return;
    }
    struct list_node *temp = last->link;
    printf("\nList: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != last->link);
}

void delete (int value)
{
    if (isEmpty())
    {
        printList();
        return;
    }
    struct list_node *temp = last;
    struct list_node *temp2 = last->link;

    do
    {
        if (temp->data == value)
        {
            if (temp->link == temp)
            {
                last = NULL;
            }
            else
            {
                temp2->link = temp->link;
                if (temp == last)
                {
                    last = temp2;
                }
            }
            printf("The node %d was deleted!", value);
            return;
        }
        temp2 = temp;
        temp = temp->link;
    } while (temp != last);
    printf("That element could not be found in the list! Could not delete");
}

void menu()
{
    int choice;
    int value;
    int spot;
    printf("\n\nCircularly Linked List\n");
    printf("Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. QUIT\n\n-> ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        insert(value);
        printList();
        break;
    case 2:
        if (isEmpty())
        {
            printList();
            break;
        }
        printf("\nWhich element do you want to delete?: ");
        scanf("%d", &value);
        delete (value);
        printList();
        break;
    case 3:
        printList();
        break;
    case 4:
        printf("Exiting Program!");
        exit(0);
    default:
        printf("Illegal Choice!");
    }
}

int main()
{
    while (1)
    {
        menu();
    }
}