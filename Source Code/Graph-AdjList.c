#include <stdio.h>

#include <stdlib.h>

struct vertex
{
	int data;
	struct vertex *next;
} * adj[50], *tail[50], *temp = NULL;

struct vertex *queue[50];
int visited[50] = {0};

int f = -1, r = -1;
void push(struct vertex *v)
{
	if (f == -1)
	{
		queue[++r] = v;
		f++;
	}
	else
	{
		queue[++r] = v;
	}
}

struct vertex *pop()
{
	if (f > r)
		return NULL;
	struct vertex *ret = queue[f];
	f++;
	return ret;
}

void traverse(struct vertex *v)
{
	struct vertex *t;
	if (v == NULL)
		return;
	visited[v->data] = 1;
	printf("%d ", v->data);

	while (v)
	{
		if (visited[v->data] == 0)
		{
			visited[v->data] = 1;
			push(v);
		}
		v = v->next;
	}
	while (1)
	{
		t = pop();
		if (t == NULL)
			break;
		traverse(adj[t->data]);
	}
}

int numVert;
void read()
{
	int vertDat;
	printf("Enter the Number of vertices\n");
	scanf("%d", &numVert);
	for (int i = 1; i <= numVert; i++)
	{
		temp = (struct vertex *)malloc(sizeof(struct vertex));

		temp->data = i;
		temp->next = NULL;
		adj[i] = tail[i] = temp;

		printf("Enter the list of vertices adjacent to v%d \nType -1 to stop\n", i);

		while (1)
		{
			scanf("%d", &vertDat);
			if (vertDat < 1)
				break;
			temp = (struct vertex *)malloc(sizeof(struct vertex));
			temp->data = vertDat;
			temp->next = NULL;
			tail[i]->next = temp;
			tail[i] = temp;
		}
	}
}

void disp()
{
	printf("Adjacency List\n");
	for (int i = 1; i <= numVert; i++)
	{
		temp = adj[i];
		while (temp != NULL)
		{
			printf("V%d--->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}
void main()
{
	read();
	disp();
	traverse(adj[1]);
}