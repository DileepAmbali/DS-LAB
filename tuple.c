#include<stdio.h>
#define MAX_TERMS 100

void input(int x[][3])
{
	int m,n,i,j,value;
	printf("Enter no of rows and columns: ");
	scanf("%d %d",&m,&n);
	x[0][0]=m;x[0][1]=n;
	printf("Enter Mx:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			{
				scanf("%d",&value);
				if(value!=0)
					{
						x[0][2]++;
						x[x[0][2]][0]=i;
						x[x[0][2]][1]=j;
						x[x[0][2]][2]=value;
					}
			}
}

void display(int x[][3])
{
	int i;
	if(x[0][2]>0)
	{	for(i=0;i<=x[0][2];i++)
			{
				printf("%d %d %d\n",x[i][0],x[i][1],x[i][2]);
			}
	}
	else
		printf("No elements\n\n");
}

void transpose(int x[][3],int y[][3])
{
	int n=x[0][2],currenty,i,j;
	y[0][0]=x[0][1];
	y[0][1]=x[0][0];
	y[0][2]=x[0][2];
	if(n>0)
	{
		currenty=1;
		for(i=0;i<x[0][1];i++)
		{
			for(j=1;j<=n;j++)
			{
				if(x[j][1]==i)
				{
					y[currenty][0]=x[j][1];
					y[currenty][1]=x[j][0];
					y[currenty][2]=x[j][2];
					currenty++;
				}
			}
		}
	}
}

void add(int a[][3],int b[][3],int sum[][3])
{
	int i=1,j=1,k=1;
	sum[0][0]=a[0][0];
	sum[0][1]=a[0][1];
	
	while(i<=a[0][2]&&j<=b[0][2])
	{
		if(a[i][0]<b[j][0])
		{
			sum[k][0]=a[i][0];
			sum[k][1]=a[i][1];
			sum[k++][2]=a[i++][2];
		}
		else if(a[i][0]>b[j][0])
		{
			sum[k][0]=b[j][0];
			sum[k][1]=b[j][1];
			sum[k++][2]=b[j++][2];
		}
		else
		{
			
			if(a[i][1]<b[j][1])
			{
				sum[k][0]=a[i][0];
				sum[k][1]=a[i][1];
				sum[k++][2]=a[i++][2];
			}
			else if(a[i][1]>b[j][1])
			{
				sum[k][0]=b[j][0];
				sum[k][1]=b[j][1];
				sum[k++][2]=b[j++][2];
			}
			else
			{
				sum[k][0]=b[j][0];
				sum[k][1]=b[j][1];
				sum[k++][2]=a[i++][2]+b[j++][2];
			}
		}
	}
	sum[0][2]=k-1;
}

void main()
{
	//Input Matrices A and B
	int a[MAX_TERMS][3];
	a[0][2]=0;
	input(a);
	
	int b[MAX_TERMS][3];
	b[0][2]=0;
	input(b);
	
	//Display A and B in Tuple form
	printf("Mx A in Tuple form:\n");
	display(a);
	printf("Mx B in Tuple form:\n");
	display(b);
	
	//Transpose of A
	int c[MAX_TERMS][3];
	transpose(a,c);
	printf("Transpose of Mx A:\n");
	display(c);
	
	//Transpose of B
	int d[MAX_TERMS][3];
	transpose(b,d);
	printf("Transpose of Mx B:\n");
	display(d);
	
	//Sum of A and B
	if(a[0][0]!=b[0][0]&&a[0][1]!=b[0][1])
		printf("Cannot add matrices, size does not match\n\n");
	else
	{
		int sum[MAX_TERMS][3];
		add(a,b,sum);
		printf("Matrix Sum in Tuple form:\n");
		display(sum);
	}
}
