#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define INFINITY 65535
/************************������ȱ���*************************/
typedef int elemtype;
typedef struct groupmatrix //����ͼ
{
	elemtype vexs[SIZE];		//�����
	int arc[SIZE][SIZE];		//�ڽӾ���
	int numvertexes, numedges;  //�������ͱ���
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
	printf("�������:\n");
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
	printf("���붥�����ͱ���:\n");
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
		printf("�����(vi,vj)���±�i,j��Ȩֵw:\n");
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