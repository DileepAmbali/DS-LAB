#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int deque_arr[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (front == (rear + 1) % MAX)
        return 1;
    else
        return 0;
}

void insert_frontEnd()
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    int item;
    printf("\nInput the element for adding in queue : ");
    scanf("%d", &item);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1;
    else
        front = front - 1;

    deque_arr[front] = item;
}

void insert_rearEnd()
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    int item;
    printf("\nInput the element for adding in queue : ");
    scanf("%d", &item);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;
    deque_arr[rear] = item;
}

void delete_frontEnd()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
    }
    item = deque_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1;
    printf("\nElement deleted from front end is : %d\n", item);
}

void delete_rearEnd()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
    }
    item = deque_arr[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear = rear - 1;
    printf("\nElement deleted from front end is : %d\n", item);
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements :\n");
    i = front;
    if (front <= rear)
    {
        while (i <= rear)
            printf("%d ", deque_arr[i++]);
    }
    else
    {
        while (i <= MAX - 1)
            printf("%d ", deque_arr[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", deque_arr[i++]);
    }
    printf("\n");
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\nDouble Ended Queue!");
        printf("\n\n1.Insert at the front end\n");
        printf("2.Insert at the rear end\n");
        printf("3.Delete from front end\n");
        printf("4.Delete from rear end\n");
        printf("5.Display\n");
        printf("6.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_frontEnd();
            display();
            break;
        case 2:
            insert_rearEnd();
            display();
            break;
        case 3:
            delete_frontEnd();
            display();
            break;
        case 4:
            delete_rearEnd();
            display();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("QUIT\n");
            exit(1);
        default:
            printf("\nWrong choice\n");
        }
    }
}