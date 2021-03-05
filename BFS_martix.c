#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define infinity 65535
/************************广度优先遍历*************************/
typedef int elemtype;
typedef struct groupmatrix //无向图
{
	elemtype vexs[SIZE];		//顶点表
	int arc[SIZE][SIZE];		//邻接矩阵
	int numvertexes, numedges;  //顶点数和边数
}group;

typedef struct queuelist
{
	elemtype data;
	struct queuelist* next;
}queuelist;

typedef struct queue
{
	queuelist* front, * rear;
}queue;

void initqueue(queue* q);
void enqueue(queue* q,int e);
void dequeue(queue* q, int* e);
void initgroup(group* g);
void bfstraverse(group g);	

int visit[SIZE];

int main(void)
{
	group g;
	initgroup(&g);
	bfstraverse(g);
	return 0;
}

void initqueue(queue* q)
{
	q->front = (queuelist*)malloc(sizeof(queuelist));
	q->front->next = NULL;
	q->rear = q->front;
	
}

void enqueue(queue* q,int e)
{
	queuelist* newnode = (queuelist*)malloc(sizeof(queuelist));
	newnode->data = e;
	newnode->next = NULL;
	q->rear->next = newnode;
	q->rear = newnode;
}

void dequeue(queue* q, int* e)
{
	if (q->front->next == NULL)
	{
		printf("队空");
		return;
	}
	if (q->front->next == q->rear)
	{
		*e = q->rear->data;
		free(q->rear);
		q->rear = q->front;
		q->front->next = NULL;
	}
	else
	{
		queuelist* newnode = (queuelist*)malloc(sizeof(queuelist));
		newnode = q->front->next;
		*e = newnode->data;
		q->front->next = newnode->next;
		free(newnode);
	}
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

void bfstraverse(group g)
{
	int i, j;
	queue q;
	initqueue(&q);
	for (i = 0; i < g.numvertexes; i++)
	{
		visit[i] = 0;
	}
	for (i = 0; i < g.numvertexes; i++)
	{
		if (0 == visit[i])		//没访问过就处理
		{
			visit[i] = 1;
			printf("v%d ", g.vexs[i]);
			enqueue(&q, i);			//未访问进队列
			while (q.front->next != NULL)
			{
				dequeue(&q, &i);	//将当前所有顶点出队列并记录
				for (j = 0; j < g.numvertexes; j++)   //判断其他顶点与当前顶点是否存在边且未访问
				{
					if (visit[j] == 0 && g.arc[i][j] != 0)
					{
						visit[j] = 1;
						printf("v%d ", g.vexs[j]);
						enqueue(&q, j);
					}
				}
			}
		}
	}
	
}
