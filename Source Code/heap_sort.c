#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int list[], int n, int i)
{
	int large = i;
	int l = 2 * i;
	int r = (2 * i) + 1;
	if (l <= n && list[l] > list[large])
		large = l;
	if (r <= n && list[r] > list[large])
		large = r;
	if (large != i)
	{
		swap(&list[large], &list[i]);
		maxHeapify(list, n, large);
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", list[i]);
	}
}

void heapSort(int list[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		maxHeapify(list, n, i);
	}
	for (int i = n; i >= 1; i--)
	{
		swap(&list[1], &list[i]);
		maxHeapify(list, n, 1);
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
		scanf("%d", &list[i + 1]);
	}
	printf("\nThe unsorted array: ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", list[i]);
	}
	// sprintf("\nAfter selection sort: ");
	heapSort(list, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", list[i]);
	}
}