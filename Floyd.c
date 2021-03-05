#include<stdio.h>
#include<stdlib.h>
#define SIZE 16
#define INFINITY 65535
typedef struct group
{
	int vexs[SIZE];
	int arc[SIZE][SIZE];
	int numvertexes, numedges;
}group;

void initgroup(group* g);
void flovd(group g, int(*p)[SIZE], int(*d)[SIZE]);

int main(void)
{
	group g;
	initgroup(&g);
	int p[SIZE][SIZE], d[SIZE][SIZE];
	flovd(g, p, d);
	int i, j, k, w;
	printf("输入起始点和终点\n");
	scanf("%d,%d", &i, &j);
	int t = 0;
	for (w = 0; w < g.numvertexes - 1; w++)
	{
		if (t == 1)
			break;
		printf("v%d ", i);
		k = p[i][j];
		i = k;
		if (i == j)
			t = 1;
	}

	return 0;
}

void initgroup(group* g)
{
	int i, j, k, w;
	printf("输入顶点数和边数:\n");
	scanf("%d,%d", &g->numvertexes, &g->numedges);
	for (i = 0; i < g->numvertexes; i++)
	{
		for (j = 0; j < g->numvertexes; j++)
		{
			if (i == j)
			{
				g->arc[i][j] = 0;
				continue;
			}
			g->arc[i][j] = INFINITY;
		}
	}
	for (k = 0; k < g->numedges; k++)
	{
		printf("输入边(vi,vj)的下标i,j和权值w\n");
		scanf("%d,%d,%d", &i, &j, &w);
		g->arc[i][j] = g->arc[j][i] = w;
	}
}

void flovd(group g, int (*p)[SIZE],int (*d)[SIZE])
{
	int v, w, k;
	for (v = 0; v < g.numvertexes; v++)
	{
		for (w = 0; w < g.numvertexes; w++)
		{
			d[v][w] = g.arc[v][w];
			p[v][w] = w;
		}
	}
	for (k = 0; k < g.numvertexes; k++)
	{
		for (v = 0; v < g.numvertexes; v++)
		{
			for (w = 0; w < g.numvertexes; w++)
			{
				if (d[v][w] > d[v][k] + d[k][w])
				{
					d[v][w] = d[v][k] + d[k][w];
					p[v][w] = p[v][k];
				}
			}
		}
	}
}