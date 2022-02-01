#include <stdio.h>

#define MAX 100

void matIn(int a[20][20], int row, int col)
{
	printf("Enter elements of the matrix:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void convSparse(int a[][20], int row, int col, int tup[MAX][3])
{
	int count = 0;
	tup[0][0] = row;
	tup[0][1] = col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] != 0)
			{
				count++;
				tup[count][0] = i;
				tup[count][1] = j;
				tup[count][2] = a[i][j];
			}
		}
	}
	tup[0][2] = count;
}

void matDisp(int a[][20], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void sparseDisp(int sp[][3])
{
	for (int i = 0; i <= sp[0][2]; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", sp[i][j]);
		}
		printf("\n");
	}
}

void transpose(int sp[][3], int t[][3])
{
	t[0][0] = sp[0][1];
	t[0][1] = sp[0][0];
	t[0][2] = sp[0][2];
	int curr = 1;
	for (int i = 0; i < sp[0][0]; i++)
	{
		for (int j = 1; j <= sp[0][2]; j++)
		{
			if (sp[j][1] == i)
			{
				t[curr][0] = sp[j][1];
				t[curr][1] = sp[j][0];
				t[curr][2] = sp[j][2];
				curr++;
			}
		}
	}
}

void sum(int sp1[][3], int sp2[][3], int spsum[][3])
{
	int a = 1, b = 1, cnt = 1;
	spsum[0][0] = sp1[0][0];
	spsum[0][1] = sp1[0][1];
	while (a <= sp1[0][2] && b <= sp2[0][2])
	{
		if (sp1[a][0] < sp2[b][0])
		{
			spsum[cnt][0] = sp1[a][0];
			spsum[cnt][1] = sp1[a][1];
			spsum[cnt][2] = sp1[a][2];
			cnt++;
			a++;
		}
		else if (sp1[a][0] > sp2[b][0])
		{
			spsum[cnt][0] = sp2[b][0];
			spsum[cnt][1] = sp2[b][1];
			spsum[cnt][2] = sp2[b][2];
			cnt++;
			b++;
		}

		else if (sp1[a][0] == sp2[b][0])
		{
			if (sp1[a][1] < sp2[b][1])
			{
				spsum[cnt][0] = sp1[a][0];
				spsum[cnt][1] = sp1[a][1];
				spsum[cnt][2] = sp1[a][2];
				cnt++;
				;
				a++;
			}

			else if (sp1[a][1] > sp2[b][1])
			{
				spsum[cnt][0] = sp2[b][0];
				spsum[cnt][1] = sp2[b][1];
				spsum[cnt][2] = sp2[b][2];
				cnt++;
				b++;
			}

			else if (sp1[a][1] == sp2[b][1])
			{
				if (sp1[a][2] + sp2[b][2] == 0)
				{
					a++;
					b++;
					continue;
				}
				spsum[cnt][0] = sp1[a][0];
				spsum[cnt][1] = sp1[a][1];
				spsum[cnt][2] = sp1[a][2] + sp2[b][2];
				cnt++;
				a++;
				b++;
			}
		}
	}
	spsum[0][2] = cnt - 1;
}

int main()
{
	int mat1[20][20], mat2[20][20];
	int r1, r2, c1, c2;
	int tup1[MAX][3], tup2[MAX][3], trans1[MAX][3], trans2[MAX][3], sum_tup[MAX][3];

	printf("Enter the no of rows and columns of first matrix: ");
	scanf("%d %d", &r1, &c1);

	matIn(mat1, r1, c1);

	printf("Enter the no of rows and columns of second matrix: ");
	scanf("%d %d", &r2, &c2);

	matIn(mat2, r2, c2);

	convSparse(mat1, r1, c1, tup1);
	convSparse(mat2, r2, c2, tup2);

	printf("\nMATRIX 1 in SPARSE FORM\n");
	sparseDisp(tup1);
	printf("\n");

	printf("MATRIX 2 in SPARSE FORM\n");
	sparseDisp(tup1);
	printf("\n");

	printf("TRANSPOSE OF SPARSE MATRIX 1\n");
	transpose(tup1, trans1);
	sparseDisp(trans1);
	printf("\n");

	printf("TRANSPOSE OF SPARSE MATRIX 2\n");
	transpose(tup2, trans2);
	sparseDisp(trans2);
	printf("\n");

	if (tup1[0][0] == tup2[0][0] && tup1[0][1] == tup2[0][1])
	{
		sum(tup1, tup2, sum_tup);
		if (sum_tup[0][2] == 0)
		{
			printf("NO ELEMENTS IN THE SUM SPARSE MATRIX FORM\n");
		}
		else
		{
			printf("SUM OF SPARSE MATRIX 1 AND 2\n");
			sparseDisp(sum_tup);
			printf("\n");
		}
	}
	else
		printf("Tough luck Buddy! Matrix size different!");
	printf("\n");

	return 0;
}
