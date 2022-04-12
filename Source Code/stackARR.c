#include <stdio.h>
#include <stdlib.h>

#define size 10
int stack[size];
int top = -1;
int stfull()
{
	if (top >= size - 1)
		return 1;
	else
		return 0;
}

void push(int item)
{
	top++;
	stack[top] = item;
}

int stempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int pop()
{
	int item;
	item = stack[top];
	top--;
	return (item);
}

void display()
{
	int i;
	if (stempty())
		printf("\nStack Is Empty!");
	else
	{
		printf("\nStack\n");
		for (i = top; i >= 0; i--)
			printf("\n%d", stack[i]);
	}
}

int main()
{
	int item, choice;
	printf("\nImplementation Of Stack Using Array");

	do
	{
		printf("\n\n1.Push \n2.Pop \n3.Display \n4.Exit\n");
		printf("\nEnter Your Choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter The item to be pushed : ");
			scanf("%d", &item);

			if (stfull())
				printf("\nStack is Full!");
			else
				push(item);
			display();
			break;
		case 2:
			if (stempty())
				printf("\nEmpty stack!Underflow !!");
			else
			{
				item = pop();
				printf("\nThe popped element is %d", item);
			}
			display();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		}
	} while (1);
	return 0;
}