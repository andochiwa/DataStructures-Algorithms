#include<stdio.h>
#define SIZE 10

typedef int vertextype;

typedef struct edgenode
{
	int adjvex;
	struct edgenode* next;
}edgenode;

typedef struct vertexnode
{
	vertextype data;
	edgenode* firstedge;
}vertexnode;

typedef struct
{
	vertexnode adjlist[SIZE];
	int numvertexes, numedges;
}group;

void initgroup(group* g);
void dfstraverse(group g);
void dfs(group g,int i);

int visit[SIZE];

int main(void)
{
	group g;
	initgroup(&g);
	dfstraverse(g);
	return 0;
}

void initgroup(group* g)
{
	int i, j, k;
	edgenode* p,*new;
	printf("输入顶点数和边数:\n");
	scanf("%d,%d", &g->numvertexes, &g->numedges);
	for (i = 0; i < g->numvertexes; i++)
	{
		printf("输入顶点:\n");
		scanf("%d", &g->adjlist[i].data);
		g->adjlist[i].firstedge = (edgenode*)malloc(sizeof(edgenode));
		g->adjlist[i].firstedge->next = NULL;
		p = g->adjlist[i].firstedge;
	}
	for (k = 0; k < g->numedges; k++)
	{
		printf("输入边(vi,vj)的下标i,j\n");
		scanf("%d,%d", &i, &j);
		for (p = g->adjlist[i].firstedge; p->next != NULL; p = p->next);
		new = (edgenode*)malloc(sizeof(edgenode));
		new->adjvex = j;
		new->next = NULL;
		p->next = new;
		p = new;

		for (p = g->adjlist[j].firstedge; p->next != NULL; p = p->next);
		new = (edgenode*)malloc(sizeof(edgenode));
		new->adjvex = i;
		new->next = NULL;
		p->next = new;
		p = new;
	}
}

void dfstraverse(group g)
{
	int i;
	for (i = 0; i < g.numvertexes; i++)
	{
		visit[i] = 0;
	}
	for (i = 0; i < g.numvertexes; i++)
	{
		if (visit[i] == 0)
			dfs(g, i);
	}
}

void dfs(group g,int i)
{
	edgenode* p = g.adjlist[i].firstedge;
	visit[i] = 1;
	printf("v%d ", g.adjlist[i].data);
	while (p->next != NULL)
	{
		p = p->next;
		if (visit[p->adjvex] == 0)
		{
			dfs(g, p->adjvex);
		}
	}
}