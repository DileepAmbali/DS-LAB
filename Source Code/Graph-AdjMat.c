#include <stdio.h>

int adj[50][50], n;

int visited[50] = {0};

void dataInput()
{
	int ad;
	printf("Enter the Number of vertices in the graph\n");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		printf("Enter the list of vertices adjacent to v%d \nType '-1' to stop\n", i);
		while (1)
		{
			scanf("%d", &ad);
			if (ad < 1)
				break;
			adj[i][ad] = 1;
		}
	}
}

void traverse(int r)
{
	visited[r] = 1;
	int k = 1;
	printf("%d ", r);
	while (k <= n)
	{
		if (adj[r][k] == 1)
		{
			if (visited[k] == 0)
				traverse(k);
		}

		k++;
	}
}

void display()
{
	printf("Adjacency Matrix\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", adj[i][j]);
		printf("\n");
	}
}
void main()
{
	dataInput();
	display();
	printf("\nDepth first Traversal: ");
	traverse(1);
}