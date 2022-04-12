#include <stdio.h>

#define MAX 100

int rear = -1;

int prioQ[MAX][2];

void insert(int val, int priority)
{
	if (rear == MAX - 1)
		printf("Queue overflow!");
	else
	{
		prioQ[++rear][0] = val;
		prioQ[rear][1] = priority;
	}
}

void delete ()
{
	if (rear == -1)
		return;
	else
	{
		int temp;
		int ptr, prioComp = prioQ[0][1];
		int i;
		for (i = 0; i <= rear; i++)
		{
			if (prioQ[i][1] > prioComp)
				ptr = i;
		}
		temp = prioQ[ptr][0];
		for (i = ptr; i < rear; i++)
		{
			prioQ[i][0] = prioQ[i + 1][0];
			prioQ[i][1] = prioQ[i + 1][1];
		}
		rear--;
		printf("%d deleted!\n\n", temp);
	}
}

void display()
{
	int i;
	if (rear == -1)
		printf("Q Empty!\n");
	else
	{
		printf("The queue:\n");
		printf("DATA\t|\tPrio\n");
		for (i = 0; i <= rear; i++)
		{
			printf("%d\t|\t%d\n", prioQ[i][0], prioQ[i][1]);
		}
	}
}

int menu()
{
	int choice;
	int val, prio;
	printf("\nPriority QUEUE!\n");
	printf("1: Insert\n");
	printf("2: Delete\n");
	printf("3: Display\n");
	printf("4: QUIT\n");
	printf("-> ");
	scanf("%d", &choice);
	printf("\n");
	switch (choice)
	{
	case 1:
		printf("Enter the value to be inserted: ");
		scanf("%d", &val);
		printf("Enter the priority of that element: ");
		scanf("%d", &prio);
		printf("\n");
		insert(val, prio);
		display();
		break;
	case 2:

		delete ();
		display();
		break;
	case 3:
		printf("\n");
		display();
		break;
	case 4:
		return 0;
	default:
		printf("Invalid Choice!");
	}
	return 1;
}

int main()
{
	while (menu())
	{
	}
	return 0;
}
