#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insetionSort(int list[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = i;
		while (list[temp] < list[temp - 1] && temp > 0)
		{
			swap(&list[temp], &list[temp - 1]);
			temp--;
		}
	}
}

void main()
{
	int n;
	int list[10000];
	printf("How many elements int the list: ");
	scanf("%d", &n);
	printf("Enter %d numbers: \n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}
	printf("\nThe unsorted array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\nAfter selection sort: ");
	insetionSort(list, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
}