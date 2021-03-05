#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define INFINITY 65535
#define MAXEDGES 15
#define MAXVES 9
/************************������ȱ���*************************/
typedef int elemtype;
typedef struct groupmatrix //����ͼ
{
	elemtype vexs[SIZE];		//�����
	int arc[SIZE][SIZE];		//�ڽӾ���
	int numvertexes, numedges;  //�������ͱ���
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
	edge edges[MAXEDGES];			//�߼�����
	int parent[MAXVES];				//�жϱ�����Ƿ��γɻ�·
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
	for (i = 0; i < g.numedges - 1; i++)		//ð�ݴ�С��������edges����
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
		if (n != m)							//�鲢��
		{
			parent[n] = m;
			printf("(%d,%d) ", edges[i].begin, edges[i].end);
		}
	}
}