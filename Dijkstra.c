#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define INFINITY 65535
/************************广度优先遍历*************************/
typedef int elemtype;
typedef struct groupmatrix //无向图
{
	elemtype vexs[SIZE];		//顶点表
	int arc[SIZE][SIZE];		//邻接矩阵
	int numvertexes, numedges;  //顶点数和边数
}group;

void initgroup(group* g);
void dijkstra(group g, int v0, int* p, int* d);

int main(void)
{
	int i, v;
	group g;
	int p[SIZE];
	int d[SIZE];
	initgroup(&g);
	printf("输入起点:\n");
	scanf("%d", &v);
	dijkstra(g, v, &p, &d);
	for (i = 0; i < g.numvertexes; i++)
	{
		printf("v%d ", p[i]);
	}
	return 0;
}


void initgroup(group* g)
{
	int i, j, k,w;
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
		printf("输入边(vi,vj)的下标i,j和权值w:\n");
		scanf("%d,%d,%d", &i, &j,&w);
		g->arc[i][j] = w;
		g->arc[j][i] = g->arc[i][j];
	}
}

void dijkstra(group g, int v0, int* p, int* d)
{
	int i, j, k, min;
	int final[SIZE];
	for (i = 0; i < g.numvertexes; i++)
	{
		p[i] = 0;
		final[i] = 0;
		d[i] = g.arc[v0][i];
	}
	final[0] = 1;
	for (i = 0; i < g.numvertexes; i++)
	{
		min = INFINITY;
		k = 0;
		for (j = 0;j < g.numvertexes;j++)
		{
			if (final[j] == 0 && d[j] < min)
			{
				min = d[j];
				k = j;
			}
		}
		final[k] = 1;

		for (j = 0; j < g.numvertexes; j++)
		{
			if (final[j] == 0 && min + g.arc[k][j] < d[j])
			{
				d[j] = min + g.arc[k][j];
				p[j] = k;
			}
		}
	}
}