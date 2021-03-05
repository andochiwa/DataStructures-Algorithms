#include<stdio.h>
#define SIZE 10
#define infinity 65535
//**********************�����������*************************************//
typedef int elemtype;
typedef struct groupmatrix //����ͼ
{
	elemtype vexs[SIZE];		//�����
	int arc[SIZE][SIZE];		//�ڽӾ���
	int numvertexes, numedges;  //�������ͱ���
}group;

////////////////////////������ȱ���
void initgroup(group* g);
void dfstraverse(group g);	//��ʼ��visit����Ϊ0�������������ͨͼ���õ�i�������������
void dfs(group g,int i);	//���������ͨͼ�������i�������������	

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
	printf("���붥�����ͱ���:\n");
	scanf("%d,%d", &g->numvertexes, &g->numedges);
	for (i = 0; i < g->numvertexes; i++)
	{
		printf("���붥��%d:\n", i);
		scanf("%d", &g->vexs[i]);
	}
	for (i = 0; i < g->numvertexes; i++)
	{
		for (j = 0; j < g->numvertexes; j++)
		{
			g->arc[i][j] = 0;
		}
	}
	for (k = 0; k < g->numedges; k++)
	{
		printf("�����(vi,vj)���±�i �±�j:\n");
		scanf("%d,%d", &i, &j);
		g->arc[i][j] = 1;
		g->arc[j][i] = g->arc[i][j];
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
		if (visit[i] == 0) //��δ���ʹ��Ķ������dfs���������ͨͼֻ�����һ��
			dfs(g, i);
	}
}

void dfs(group g,int i)
{
	int j;
	visit[i] = 1;
	printf("v%d ", g.vexs[i]);
	for (j = 0;j < g.numvertexes; j++)
	{
		if (visit[j] == 0 && g.arc[i][j] == 1)
			dfs(g, j);
	}
	return;
}