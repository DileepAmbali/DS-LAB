#include <stdio.h>

int linearSearch(int A[], int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] == search)
            return i;
    }
    return -1;
}

int main()
{

    int A[50], search, i, size, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements: \n", size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the number to be searched for: ");
    scanf("%d", &search);

    pos = linearSearch(A, size, search);

    if (pos == -1)
        printf("The number %d was not found in the array!", search);

    else
        printf("The number %d was found at index %d", search, pos);

    return 0;
}