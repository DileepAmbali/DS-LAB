#include <stdio.h>

typedef struct table
{
	int occupied;
	int data;
} table;

table t[50];

int hash(int n, int m)
{
	return n % m;
}

void insertIntoTable(int n)
{
	int index = hash(n, c11);
	do
	{
		if (t[index].occupied == 0)
		{
			t[index].occupied = 1;
			t[index].data = n;
			break;
		}
		else
			index = (index + 1) % 11;
	} while (index != hash(n, 11));
}

void main()
{
	int i, ele;
	printf("How many elements to add: ");
	scanf("%d", &i);
	if (i > 11)
		printf("Too many elements.");
	else
	{
		while (i > 0)
		{
			printf("Enter a number to store in the table: ");
			scanf("%d", &ele);
			insertIntoTable(ele);
			i--;
		}
		printf("The table\n");
		printf("INDEX\tVALUE\n");
		for (int i = 0; i < 11; i++)
		{
			printf("%d\t%d\n", i, t[i].data);
		}
	}
}