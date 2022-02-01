#include <stdio.h>

int binarySearch(int A[], int size, int search, int low, int high)
{

    int mid = (high + low) / 2;

    if (low == high)
        return -1;

    if (search == A[mid])
        return mid;

    if (search < A[mid])
        return binarySearch(A, size, search, low, mid - 1);

    else
        return binarySearch(A, size, search, mid + 1, high);
}

int main()
{
    int A[50], search, size, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements: \n", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the number to be searched for: ");
    scanf("%d", &search);

    pos = binarySearch(A, size, search, 0, size - 1);

    if (pos == -1)
        printf("The number %d was not found in the array!", search);

    else
        printf("The number %d was found at index %d", search, pos);

    return 0;
}