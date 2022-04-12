#include <stdio.h>

int A[20], size;

void binarySearch()
{
    int search;
    printf("Enter the number to be searched for: ");
    scanf("%d", &search);

    int low = 0;
    int high = size;
    int mid;
    while (low != size - 1 && high != 0)
    {
        mid = (high + low) / 2;
        if (A[mid] == search)
        {
            printf("The number %d was found at index %d", search, mid);
            return;
        }
        else if (A[mid] > search)
        {
            high = mid;
        }
        else if (A[mid] < search)
        {
            low = mid;
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
    binarySearch();
}