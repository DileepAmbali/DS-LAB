#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char infix_exp[50], rev_infix[50], prefix_exp[50];
int gitt = 0;

char stack[50];
int top = -1;

void display(char exp[]);

void reverser();

int isEmpty();

int isFull();

int precedence(char c);

int checkAssociation(char c);

int typeFinder(char c);

void push(char c);

char pop();

char peak();

void output(char c);

void in2pre();

void main()
{
	printf("Enter the infix expression: ");
	gets(infix_exp);
	in2pre();
	display(prefix_exp);
}

void display(char exp[])
{
	puts(exp);
}

void in2pre()
{
	char c;
	for (int i = 0; i < strlen(infix_exp); i++)
	{
		rev_infix[i] = infix_exp[strlen(infix_exp) - i - 1];
	}

	for (int i = 0; i < strlen(infix_exp); i++)
	{
		c = rev_infix[i];
		switch (typeFinder(c))
		{
		case 1: // is number/variable
			prefix_exp[gitt] = c;
			gitt++;
			break;
		case 2: // operation
			if (isEmpty())
				push(c);
			else if (isFull())
			{
				printf("Stack overflow! Exiting program!");
				exit(1);
			}
			else
			{
				while (1)
				{
					if (precedence(peak()) == precedence(c))
						if (checkAssociation(c) == 1)
						{
							push(c);
							break;
						}
						else
						{
							prefix_exp[gitt] = pop();
							gitt++;
						}
					else if (precedence(peak()) < precedence(c))
					{
						push(c);
						break;
					}
					else
					{
						prefix_exp[gitt] = pop();
						gitt++;
					}
				}
			}
			break;
		case 3:
			push(c);
			break;
		case 4:
			while (peak() != '(')
			{
				prefix_exp[gitt] = pop();
				gitt++;
			}
		default:
			printf("Something went wrong!");
			exit(1);
			break;
		}
	}
	while (!isEmpty())
	{
		prefix_exp[gitt] = pop();
		gitt++;
	}

	display(prefix_exp);

	for (int i = 0; i < strlen(infix_exp) / 2; i++)
	{
		char c = prefix_exp[i];
		prefix_exp[i] = prefix_exp[strlen(infix_exp) - i - 1];
		prefix_exp[strlen(infix_exp) - i - 1] = c;
	}
}

int typeFinder(char c)
{
	if (isalnum(c))
		return 1;

	else if (c == '-' || c == '+' || c == '*' || c == '/' || c == '^')
		return 2;

	else if (c == '(')
		return 3;

	else if (c == ')')
		return 4;
	else
		return -1;
}

int isEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}

int isFull()
{
	if (top == 49)
		return 1;
	return 0;
}

char peak()
{
	if (isEmpty())
	{
		printf("Stack underflow!");
		exit(1);
	}
	return stack[top];
}

char pop()
{
	if (isEmpty())
	{
		printf("Stack underflow!");
		exit(1);
	}
	char c = stack[top];
	top--;
	return c;
}

void push(char c)
{
	if (isFull())
	{
		printf("Stack overflow!");
		exit(1);
	}
	else
		stack[++top] = c;
}

int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '(' || c == ')')
		return 0;
	else
		return -1;
}

int checkAssociation(char c)
{
	if (c == '/' || c == '*' || c == '-' || c == '+')
		return 1;
	else if (c == '^')
		return 2;
	else
		return -1;
}