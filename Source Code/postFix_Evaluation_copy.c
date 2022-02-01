#include <stdio.h>

#define MAX 100

char stack[MAX];

int stack_Top = -1;

void push(char item)
{
    if (stack_Top >= MAX)
    {
        printf("Stack overflow!");
    }
}

int main()
{
    return 0;
}