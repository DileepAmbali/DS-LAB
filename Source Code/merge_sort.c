#include <stdio.h>

void merge(int a[], int l, int h, int m)
{
	int i = 0, j = 0, k = 0;
	int na, nb;
	na = m - l + 1;
	nb = h - m;
	int sp1[na],
		sp2[nb];
	for (i = 0; i < na; i++)
	{
		sp1[i] = a[l + i];
	}
	for (i = 0; i < nb; i++)
	{
		sp2[i] = a[m + i + 1];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < na && j < nb)
	{
		if (sp1[i] < sp2[j])
		{
			a[k] = sp1[i];
			i++;
		}
		else
		{
			a[k] = sp2[j];
			j++;
		}
		k++;
	}

	while (i < na)
	{
		a[k] = sp1[i];
		i++;
		k++;
	}

	while (j < nb)
	{
		a[k] = sp2[j];
		j++;
		k++;
	}
}

void mergeSort(int list[], int l, int h)
{
	if (l < h)
	{
		int m = (l + h) / 2;
		mergeSort(list, l, m);
		mergeSort(list, m + 1, h);
		merge(list, l, h, m);
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
	printf("\nAfter Merge sort: ");

	mergeSort(list, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
}