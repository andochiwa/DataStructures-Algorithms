#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct bitree
{
	int data;
	struct bitree* lchild, * rchild;
}bitree;

int searchBST(bitree* t, int key, bitree* f, bitree** p);
int insertBST(bitree** t, int key);
int deleteBST(bitree** t, int key);
void delete(bitree** t);
void traverseBST(bitree* t);

int main(void)
{
	int i;
	bitree* t = NULL;
	printf("创建二叉搜索树，0结束\n");
	scanf("%d", &i);
	while (i != 9)
	{
		insertBST(&t, i);
		scanf("%d", &i);
	}
	traverseBST(t);
	printf("输入要删除的点\n");
	scanf("%d", &i);
	deleteBST(&t, i);
	traverseBST(t);
	return 0;
}

int searchBST(bitree* t, int key, bitree* f, bitree** p)
{
	if (t == NULL)
	{
		*p = f;
		return false;
	}
	else if (key == t->data)
	{
		*p = t;
		return true;
	}
	else if (key < t->data)
	{
		return searchBST(t->lchild, key, t, p);
	}
	else
	{
		return searchBST(t->rchild, key, t, p);
	}
}

int insertBST(bitree** t, int key)
{
	bitree* new, * p;
	if (searchBST(*t, key, NULL, &p) == false)
	{
		new = (bitree*)malloc(sizeof(bitree));
		new->data = key;
		new->lchild = new->rchild = NULL;
		if (p == NULL)
		{
			*t = new;
		}
		else if (key < p->data)
		{
			p->lchild = new;
		}
		else if (key > p->data)
		{
			p->rchild = new;
		}
		return true;
	}
	else
		return false;
}

int deleteBST(bitree** t, int key)
{
	if (*t == NULL)
	{
		return false;
	}
	else
	{
		if (key == (*t)->data)
		{
			delete(t);
			return true;
		}
		else if (key < (*t)->data)
		{
			return deleteBST(&(*t)->lchild, key);
		}
		else
		{
			return deleteBST(&(*t)->rchild, key);
		}
		
	}
}

void delete(bitree** t)
{
	bitree* new1, * new2;
	if ((*t)->lchild == NULL)
	{
		new1 = *t;
		*t = (*t)->rchild;
		free(new1);
	}
	else if ((*t)->rchild == NULL)
	{
		new1 = *t;
		*t = (*t)->lchild;
		free(new1);
	}
	else
	{
		new1 = *t; new2 = (*t)->lchild;
		while (new2->rchild != NULL)
		{
			new1 = new2;
			new2 = new2->rchild;
		}
		(*t)->data = new2->data;
		if (new1 != *t)
		{
			new1->rchild = new2->lchild;
		}
		else
		{
			new1->lchild = new2->lchild;
		}
		free(new2);
	}
}

void traverseBST(bitree* t)
{
	if (t == NULL)
		return;
	traverseBST(t->lchild);
	printf("%d ", t->data);
	traverseBST(t->rchild);
}