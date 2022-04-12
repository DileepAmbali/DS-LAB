#include <stdio.h>

int A[50], size;
void linearSearch(int A[])
{
    int search;
    printf("Enter the number to be searched for: ");
    scanf("%d", &search);

    for (int i = 0; i < size; i++)
    {
        if (A[i] == search)
        {
            printf("The number %d was found at index %d", search, i);
            return;
        }
    }
    printf("The number %d was not found in the array!", search);
}

void readData()
{
    int i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements: \n", size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }
}

int main()
{
    readData();
    linearSearch(A);
}