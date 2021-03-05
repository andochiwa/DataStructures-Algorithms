#include<stdio.h>
#define SIZE 10
#define infinity 65535
//**********************深度优先搜索*************************************//
typedef int elemtype;
typedef struct groupmatrix //无向图
{
	elemtype vexs[SIZE];		//顶点表
	int arc[SIZE][SIZE];		//邻接矩阵
	int numvertexes, numedges;  //顶点数和边数
}group;

////////////////////////深度优先遍历
void initgroup(group* g);
void dfstraverse(group g);	//初始化visit数组为0，且如果不是连通图，让第i个顶点继续遍历
void dfs(group g,int i);	//如果不是连通图，进入第i个顶点继续遍历	

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
	printf("输入顶点数和边数:\n");
	scanf("%d,%d", &g->numvertexes, &g->numedges);
	for (i = 0; i < g->numvertexes; i++)
	{
		printf("输入顶点%d:\n", i);
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
		printf("输入边(vi,vj)的下标i 下标j:\n");
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
		if (visit[i] == 0) //对未访问过的顶点调用dfs，如果是连通图只会访问一次
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