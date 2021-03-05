#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef int vertextype;

typedef struct queuelist
{
	int data;
	struct queuelist* next;
}queuelist;

typedef struct queue
{
	queuelist* front, * rear;
}queue;

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

void initqueue(queue* q);
void enqueue(queue* q, int e);
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

void enqueue(queue* q, int e)
{
	queuelist* newnode = (queuelist*)malloc(sizeof(queuelist));
	newnode->data = e;
	q->rear->next = newnode;
	newnode->next = NULL;
	q->rear = newnode;
}

void dequeue(queue* q, int* e)
{
	if (NULL == q->front->next)
		return;
	queuelist* newnode = (queuelist*)malloc(sizeof(queuelist));
	if (q->front->next == q->rear)
	{
		(*e) = q->rear->data;
		free(q->rear);
		q->rear = q->front;
		q->front->next = NULL;
	}
	else
	{
		newnode = q->front->next;
		q->front->next = newnode->next;
		*e = newnode->data;
		free(newnode);
	}
}

void initgroup(group* g)
{
	int i, j, k;
	edgenode* p, * newnode;
	printf("输入顶点数和边数\n");
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
		newnode = (edgenode*)malloc(sizeof(edgenode));
		newnode->adjvex = j;
		newnode->next = NULL;
		p->next = newnode;
		p = newnode;

		for (p = g->adjlist[j].firstedge; p->next != NULL; p = p->next);
		newnode = (edgenode*)malloc(sizeof(edgenode));
		newnode->adjvex = i;
		newnode->next = NULL;
		p->next = newnode;
		p = newnode;
	}
}

void bfstraverse(group g)
{
	int i, j;
	queue q;
	edgenode* newnode;
	for (i = 0; i < g.numvertexes; i++)
	{
		visit[i] = 0;
	}
	initqueue(&q);
	for (i = 0; i < g.numvertexes; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			printf("%d ", g.adjlist[i].data);
			enqueue(&q, i);
			while (q.front->next != NULL)
			{
				dequeue(&q, &i);
				newnode = g.adjlist[i].firstedge;
				while (newnode->next != NULL)
				{
					newnode = newnode->next;
					if (visit[newnode->adjvex] == 0)
					{
						visit[newnode->adjvex] = 1;
						printf("%d ", g.adjlist[newnode->adjvex].data);
						enqueue(&q, newnode->adjvex);
					}
				}
			}
		}
	}
}

