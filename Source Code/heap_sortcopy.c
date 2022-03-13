#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int list[], int n, int root)
{
	int l = 2 * root;
	int r = (2 * root) + 1;
	int big = root;
	if (l <= n && list[l] > list[big])
		big = l;
	if (r <= n && list[r] > list[big])
		big = r;
	if (big != root)
	{
		swap(&list[root], &list[big]);
		maxHeapify(list, n, big);
	}
}

void heapSort(int list[], int n)
{

	for (int i = (n / 2) + 1; i >= 1; i--)
	{
		maxHeapify(list, n, i);
	}
	for (int i = n; i > 1; i--)
	{
		swap(&list[i], &list[1]);
		maxHeapify(list, i - 1, 1);
	}
}

void main()
{
	int n;
	int list[100000];
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
	printf("\nAfter selection sort: ");

	heapSort(list, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", list[i]);
	}
}