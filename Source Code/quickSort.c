#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int list[], int l, int h)
{
	if (h - l <= 1)
		return;
	int piv = l;
	int i = l;
	int j = h;

	while (i < j)
	{
		while (i < h && list[i] < list[piv])
			i++;
		while (j > l && list[j] > list[piv])
			j--;
		if (i < j)
			swap(&list[i], &list[j]);
	}
	swap(&list[piv], &list[j]);
	quickSort(list, l, j - 1);
	quickSort(list, j + 1, h);
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
	printf("\nAfter Quick sort: ");
	quickSort(list, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
}