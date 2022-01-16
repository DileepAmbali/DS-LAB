#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = 0;

void push(char item)
{
    if (top >= MAX)
    {
        printf("Stack overflow! Program Terminated!");
        exit(1);
    }
    else
        stack[++top] = item;
}

char pop()
{
    if (top < 0)
    {
        printf("Stack Underflow! Program terminating!");
        exit(1);
    }
    else
        return stack[top--];
}

bool isOperation(char item)
{
    switch (item)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
        break;
    default:
        return false;
    }
}

int precedence(char item)
{
    switch (item)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
    }
}

void converter(char infix[], char postfix[])
{
    int postCount = 0, infixCount = 0;
    char item = infix[infixCount];
    char x;
    while (item != '\0')
    {
        if (isspace(item))
        {
            item = infix[++infixCount];
            continue;
        }
        else if (item == '(')
        {
            push(item);
        }
        else if (isalnum(item))
        {
            postfix[postCount++] = item;
        }
        else if (isOperation(item))
        {
            x = pop();
            while (precedence(item) <= precedence(x))
            {
                postfix[postCount++] = x;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix[postCount++] = x;
                x = pop();
            }
        }

        else
        {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }

        item = infix[++infixCount];
    }
    postfix[postCount] = pop();
    postfix[++postCount] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("\nEnter Infix expression : ");
    gets(infix);
    converter(infix, postfix);
    printf("Postfix Expression: ");
    puts(postfix);
    return 0;
}
