#include <stdio.h>
#include <stdlib.h>

struct dllnode
{
    struct dllnode *prev;
    char data;
    struct dllnode *next;
} dllnode;

struct dllnode *front = NULL, *rear = NULL;

struct dllnode *create(char value)
{
    struct dllnode *node;
    node = (struct dllnode *)malloc(sizeof(dllnode));
    node->prev = NULL;
    node->data = value;
    node->next = NULL;
    return node;
}

void convert(char string[])
{
    int i = 0;
    char c = string[i];
    while (c != '\0')
    {
        struct dllnode *node = create(c);
        if (front == NULL)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
        i++;
        c = string[i];
    }
}

void isPalindrome()
{
    struct dllnode *temp1 = front, *temp2 = rear;
    while (temp1 != temp2 && temp1->prev != temp2)
    {
        if (temp1->data != temp2->data)
        {
            printf("Not palindrome!");
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    printf("Is a palindrome!");
}

void display()
{
    if (front == NULL)
    {
        printf("\nList Empty\n");
        return;
    }
    struct dllnode *temp = front;
    printf("\nList: NULL");
    while (temp != NULL)
    {
        printf(" <-- %c --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    char s[50];
    printf("Enter the string: ");
    gets(s);
    convert(s);
    display();
    isPalindrome();
}