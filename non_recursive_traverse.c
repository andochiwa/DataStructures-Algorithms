#include<stdio.h>
#include<stdlib.h>

typedef struct bitree
{
	char data;
	struct bitree* lchild, * rchild;
}tree;

typedef struct stacklist
{
	tree* t;
	struct stacklist* next;
}stacklist;

typedef struct
{
	stacklist* top;
}stack;

void initstack(stack* s);
void push(stack* s, tree* t);
void pop(stack* s, tree** t);
void initbitree(tree** t);
void traverse(tree* t);

int main(void)
{
	tree* t;
	initbitree(&t);
	traverse(t);
	return 0;
}

void initstack(stack* s)
{
	s->top = (stacklist*)malloc(sizeof(stack));
	s->top->next = NULL;
}

void push(stack* s, tree* t)
{
	stacklist* new = (stacklist*)malloc(sizeof(stacklist));
	new->t = t;
	new->next = s->top->next;
	s->top->next = new;
}

void pop(stack* s, tree** t)
{
	stacklist* new = s->top->next;
	(*t) = new->t;
	s->top->next = new->next;
	free(new);
}

void initbitree(tree** t)
{
	char c;
	scanf("%c", &c);
	if (c == '#')
		*t = NULL;
	else
	{
		*t = (tree*)malloc(sizeof(tree));
		(*t)->data = c;
		initbitree(&(*t)->lchild);
		initbitree(&(*t)->rchild);
	}
}

void traverse(tree* t)
{
	tree* new = t;
	stack s;
	initstack(&s);
	printf("前序非递归遍历:\n");
	push(&s, new);
	while (s.top->next != NULL)
	{
		pop(&s, &new);
		printf("%c ", new->data);
		if (new->rchild != NULL)
			push(&s, new->rchild);
		if (new->lchild != NULL)
			push(&s, new->lchild);
	}
	
	new = t;
	printf("\n中序非递归遍历:\n");
	push(&s, new);
	while (new->lchild != NULL)
	{
		push(&s, new->lchild);
		new = new->lchild;
	}
	while (s.top->next != NULL)
	{
		pop(&s, &new);
		printf("%c ", new->data);
		if (new->rchild != NULL)
		{
			push(&s, new->rchild);
			new = new->rchild;
			while (new->lchild != NULL)
			{
				push(&s, new->lchild);
				new = new->lchild;
			}
		}
	}

	new = t;
	stack s2;
	initstack(&s2);
	printf("\n后续非递归遍历:\n");
	push(&s, new);
	while (s.top->next != NULL)
	{
		pop(&s, &new);
		push(&s2, new);
		if (new->lchild != NULL)
			push(&s, new->lchild);
		if (new->rchild != NULL)
			push(&s, new->rchild);
	}
	while (s2.top->next != NULL)
	{
		pop(&s2, &new);
		printf("%c ", new->data);
	}
}
