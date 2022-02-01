#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct dllnode
{
    struct dllnode *prev;
    int data;
    struct dllnode *next;
} dllnode;

struct dllnode *front = NULL, *rear = NULL;

struct dllnode *createNode(int value)
{
    struct dllnode *node;
    node = (struct dllnode *)malloc(sizeof(dllnode));
    node->prev = NULL;
    node->data = value;
    node->next = NULL;
    return node;
}

bool isEmpty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

void initInsert(int value)
{
    struct dllnode *node = createNode(value);
    front = node;
    rear = node;
}

void insertFront(int value)
{
    struct dllnode *node = createNode(value);
    node->next = front;
    front->prev = node;
    front = node;
}

void insertRear(int value)
{
    struct dllnode *node = createNode(value);
    node->prev = rear;
    rear->next = node;
    rear = node;
}

bool insertSpot(int value, int neighbourVal)
{
    struct dllnode *node = createNode(value);
    struct dllnode *temp = front;
    while (temp != NULL)
    {
        if (temp->data == neighbourVal)
        {
            node->next = temp->next;
            temp->next = node;
            node->prev = temp;
            if (node->next == NULL)
            {
                rear = node;
                break;
            }
            temp = node->next;
            temp->prev = node;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool delete (int value)
{
    struct dllnode *temp1 = front;
    struct dllnode *temp2 = NULL;
    while (temp1 != NULL)
    {
        if (temp1->data == value)
        {
            temp2 = temp1->prev;
            temp1 = temp1->next;
            if (temp1 == NULL && temp2 == NULL)
            {
            }
            else if (temp1 == NULL)
            {
                temp2->next = NULL;
            }
            else if (temp2 = NULL)
            {
                temp1->prev = NULL;
            }
            else
            {
                temp1->prev = temp2;
                temp2->next = temp1;
            }
            return true;
        }
        temp1 = temp1->next;
    }
    return false;
}

void printList()
{
    if (isEmpty())
    {
        printf("\nList Empty\n");
        return;
    }
    struct dllnode *temp = front;
    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void menu()
{
    int choice;
    int value;
    int spot;
    printf("\nDoubly Linked List\n");
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
        if (isEmpty())
        {
            initInsert(value);
        }
        else
        {
            printf("Where do you want to insert: \n 1.Rear \n 0.Custom Spot \n-1.Front\n\n-> ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                insertRear(value);
                printf("\nThe node \"%d\" was successfuly added at the rear", value);
                break;
            case 0:
                printList();
                printf("\nNext to which list item do you want to add the new node:");
                scanf("%d", &spot);
                if (insertSpot(value, spot))
                {
                    printf("\nThe node \"%d\" was successfuly added after node \"%d\"", value, spot);
                }
                else
                {
                    printf("\nThe node was not added to the list! \"%d\" could not be found!", spot);
                }
                break;
            case -1:
                insertFront(value);
                printf("\nThe node \"%d\" was added at the front", value);
                break;

            default:
                printf("\nIllegal Choice!");
            }
        }
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
        if (delete (value))
        {
            printf("The node %d was deleted!", value);
        }
        else
        {
            printf("That element could not be found in the list! Could not delete");
        }
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