#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define INFINITY 65535
#define MAXEDGES 15
#define MAXVES 9
/************************广度优先遍历*************************/
typedef int elemtype;
typedef struct groupmatrix //无向图
{
	elemtype vexs[SIZE];		//顶点表
	int arc[SIZE][SIZE];		//邻接矩阵
	int numvertexes, numedges;  //顶点数和边数
}group;

typedef struct
{
	int begin, end, weight;
}edge;

void initgroup(group* g);
void minspantree_kruskal(group g);
int find(int* parent, int n);

int main(void)
{
	group g;
	initgroup(&g);
	minspantree_kruskal(g);
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

int find(int* parent, int n)
{
	while (parent[n] > 0)
		n = parent[n];
	return n;
}

void minspantree_kruskal(group g)
{
	int i, j, n, m;
	int k = 0;
	edge edges[MAXEDGES];			//边集数组
	int parent[MAXVES];				//判断边与边是否形成环路
	for (i = 0; i < g.numvertexes; i++)
	{
		for (j = i; j < g.numvertexes; j++)
		{
			if (g.arc[i][j] != 0 && g.arc[i][j] != INFINITY)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = g.arc[i][j];
				k++;
			}
		}
	}
	edge temp;
	for (i = 0; i < g.numedges - 1; i++)		//冒泡从小到大排序edges数组
	{
		for (j = 0; j < g.numedges - 1; j++)
		{
			if (edges[j].weight > edges[j + 1].weight)
			{
				temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < g.numvertexes; i++)
	{
		parent[i] = 0;
	}
	for (i = 0; i < g.numedges; i++)
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);
		if (n != m)							//查并集
		{
			parent[n] = m;
			printf("(%d,%d) ", edges[i].begin, edges[i].end);
		}
	}
}