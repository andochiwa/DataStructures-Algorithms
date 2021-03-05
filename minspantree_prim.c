#include<stdio.h>
#define INFINITY 65535
#define SIZE 20
/***********************最小生成树prim算法**************************/
typedef struct group
{
	int vexs[SIZE];
	int arc[SIZE][SIZE];
	int numvertexes, numedges;
}group;

void initgroup(group* g);
void minspantree_prim(group g);

int main(void)
{
	group g;
	initgroup(&g);
	minspantree_prim(g);
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
		printf("输入边(vi,vj)的下标i,j和权值w的值\n");
		scanf("%d,%d,%d", &i, &j, &w);
		g->arc[i][j] = w;
		g->arc[j][i] = g->arc[i][j];
	}
}

void minspantree_prim(group g)
{
	int i, j, k, min;
	int lowcost[SIZE], adjvex[SIZE];
	for (i = 0; i < g.numvertexes; i++)
	{
		lowcost[i] = g.arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < g.numvertexes; i++)
	{
		j = 1, k = 0;
		min = INFINITY;
		while (j < g.numvertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("(%d,%d) ", adjvex[k], k);
		lowcost[k] = 0;
		for (j = 1; j < g.numvertexes; j++)
		{
			if (lowcost[j] != 0 && g.arc[k][j] < lowcost[j])
			{
				lowcost[j] = g.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}