#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define LH -1
#define EH 0
#define RH 1

typedef struct AVLtree
{
	int data, bf;
	struct AVLtree* lchild, * rchild;
}tree;

void l_rotate(tree** t);
void r_rotate(tree** t);
void l_balance(tree** t);
void r_balance(tree** t);
bool insertAVL(tree** t, int key, int* taller);
void traversal(tree* t);

int main(void)
{
	tree* t = NULL;
	int taller;
	int key;
	printf("input value, 0 to end\n");
	while (1)
	{
		scanf("%d", &key);
		if (0 == key)
			break;
		insertAVL(&t, key, &taller);
	}
	traversal(t);
	return 0;
}

void l_rotate(tree** t)
{
	tree* new;
	new = (*t)->rchild;
	(*t)->rchild = new->lchild;
	new->lchild = *t;
	*t = new;
}

void r_rotate(tree** t)
{
	tree* new;
	new = (*t)->lchild;
	(*t)->lchild = new->rchild;
	new->rchild = *t;
	*t = new;
}

void l_balance(tree** t)
{
	tree* new, * newr;
	new = (*t)->lchild;
	switch (new->bf)
	{
	case LH:
		r_rotate(t);
		new->bf = (*t)->bf = EH;
		break;
	case RH:
		newr = new->rchild;
		switch (newr->bf)
		{
		case LH:
			(*t)->bf = RH;
			new->bf = EH;
			break;
		case EH:
			(*t)->bf = new->bf = EH;
			break;
		case RH:
			(*t)->bf = EH;
			new->bf = LH;
			break;
		}
		newr->bf = EH;
		l_rotate(&(*t)->lchild);
		r_rotate(t);
	}
}

void r_balance(tree** t)
{
	tree* new, * newl;
	new = (*t)->rchild;
	switch (new->bf)
	{
	case RH:
		l_rotate(t);
		(*t)->bf = new->bf = EH;
		break;
	case LH:
		newl = new->lchild;
		switch (newl->bf)
		{
		case RH:
			(*t)->bf = LH;
			new->bf = EH;
			break;
		case EH:
			(*t)->bf = new->bf = EH;
			break;
		case LH:
			(*t)->bf = EH;
			new->bf = RH;
			break;
		}
		newl->bf = EH;
		r_rotate(&(*t)->rchild);
		l_rotate(t);
	}
}

bool insertAVL(tree** t, int key, int* taller)
{
	if (!*t)
	{
		*t = (tree*)malloc(sizeof(tree));
		(*t)->data = key;
		(*t)->bf = EH;
		(*t)->lchild = (*t)->rchild = NULL;
		*taller = true;
	}
	else
	{
		if (key == (*t)->data)
		{
			*taller = false;
			return false;
		}
		else if (key < (*t)->data)
		{
			if (!insertAVL(&(*t)->lchild, key, taller))
			{
				return false;
			}
			if (taller)
			{
				switch ((*t)->bf)
				{
				case LH:
					l_balance(t);
					*taller = false;
					break;
				case EH:
					(*t)->bf = LH;
					*taller = true;
					break;
				case RH:
					(*t)->bf = EH;
					*taller = false;
					break;
				}
			}
		}
		else
		{
			if (!insertAVL(&(*t)->rchild, key, taller))
			{
				return false;
			}
			if (taller)
			{
				switch ((*t)->bf)
				{
				case LH:
					(*t)->bf = EH;
					*taller = false;
					break;
				case EH:
					(*t)->bf = RH;
					*taller = true;
					break;
				case RH:
					r_balance(t);
					*taller = false;
					break;
				}
			}
		}
	}
}

void traversal(tree* t)
{
	if (!t)
	{
		return;
	}
	traversal(t->lchild);
	printf("%d ", t->data);
	traversal(t->rchild);
}