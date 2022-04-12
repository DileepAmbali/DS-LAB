#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int list[], int n)
{
	int small;
	for (int i = 0; i < n - 1; i++)
	{
		small = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list[j] < list[small])
				small = j;
		}
		if (small != i)
			swap(&list[i], &list[small]);
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
	printf("\n\nAfter selection sort: ");

	selectionSort(list, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
}