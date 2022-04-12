#include <stdio.h>
#include <stdlib.h>

int cqueue[50], front = -1, rear = -1, n;
void display()
{
	int i = 0;
	if (front == -1)
	{
		printf("\nCircular Queue is empty");
	}
	else
	{
		for (i = front; i != rear; i = (i + 1) % n)
		{
			printf("%d ", cqueue[i]);
		}
		printf("%d ", cqueue[i]);
	}
	printf("\n");
}
void enqueue()
{
	int next, item, i;
	printf("Enter the element: ");
	scanf("%d", &item);

	if (front == -1)
	{
		front = 0;
		rear = 0;
		cqueue[rear] = item;
	}
	else
	{
		next = (rear + 1) % n;
		if (next != front)
		{
			rear = next;
			cqueue[rear] = item;
		}
		else
		{
			printf("\nCircular Queue is full");
		}
	}
	printf("\nThe circular queue is: ");
	display();
}
void dequeue()
{
	int item, i;
	if (front == -1)
	{
		printf("\nCircular queue is empty");
	}
	else
	{
		item = cqueue[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % n;
		}
	}
	display();
}

void main()
{
	int ch;
	printf("Enter the size of the queue: ");
	scanf("%d", &n);
	while (1)
	{
		printf("\nOperations:\n1. Enqueue\n2. Dequeue\n3. Exit");
		printf("\nEnter the choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			exit(0);
		default:
			printf("There is no such operation");
		}
	}
}