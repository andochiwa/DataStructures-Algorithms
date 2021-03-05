#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define STACKINCREMENT 10
typedef struct 
{
	int *top;
	int *base;
	int stacksize;
}stack;

void initstack(stack* s);
void push(stack* s, int e);
void pop(stack* s, int *e);
int stacklen(stack s);

int main(void)
{
	int i,x;
	int a = 0, b = 1;
	stack s;
	initstack(&s);
	printf("输入一个二进制数,按2结束\n");
	scanf("%d", &x);
	while (x != 2)
	{
		push(&s, x);
		scanf("%d", &x);
	}

	int len = stacklen(s);
	for (i = 0; i < len; i++)
	{
		pop(&s, &x);
		if (x == 1)
			a += b;
		b *= 2;
	}
	printf("%d", a);
	return 0;
}

void initstack(stack* s)
{
	s->base = (int*)malloc(sizeof(int) * SIZE);
	if (s->base == NULL)
		exit(0);
	s->top = s->base;
	s->stacksize = SIZE;
}

void push(stack* s,int e)
{
	*(s->top) = e;
	s->top++;
}

void pop(stack* s, int* e)
{
	if (s->top == s->base)
		return;
	s->top--;
	*e = *(s->top);
}

int stacklen(stack s)
{
	return (s.top - s.base);
}
