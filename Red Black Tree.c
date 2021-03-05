#include<stdio.h>
#include<stdlib.h>

typedef enum{red,black} colortype;

typedef struct rbtree
{
	int data;
	struct rbtree* lchild, * rchild, * parent;
	colortype color;
}rbtree;

typedef struct rbtree_root
{
	rbtree *root;
}rbroot;

void initrbtree(rbroot** r);
void l_rotate(rbroot** r, rbtree* t);
void r_rotate(rbroot** r, rbtree* t);
void insertrbtree(rbroot** r, int key);
void insert_rbtree(rbroot** r, rbtree* t);
void traverse(rbtree* t);

int main(void)
{
	rbroot* r;
	initrbtree(&r);
	int i, key;
	i = 0;
	srand((unsigned)time(NULL));
	while (i < 100)
	{
		key = rand();
		insertrbtree(&r, key);
		i++;
	}
	traverse(r->root);
	return 0;
}

void initrbtree(rbroot** r)
{
	*r = (rbroot*)malloc(sizeof(rbroot));
	(*r)->root = NULL;
}

void l_rotate(rbroot** r, rbtree* t)
{
	rbtree* new = t->rchild;
	t->rchild = new->lchild;	
	if (t->rchild != NULL)
		t->rchild->parent = t;
	new->parent = t->parent;
	if (t->parent == NULL)
		(*r)->root = new;
	else if (t->parent->lchild == t)
		t->parent->lchild = new;
	else
		t->parent->rchild = new;
	new->lchild = t;
	t->parent = new;
}

void r_rotate(rbroot** r, rbtree* t)
{
	rbtree* new = t->lchild;
	t->lchild = new->rchild;
	if (t->lchild != NULL)
		t->lchild->parent = t;
	new->parent = t->parent;
	if (t->parent == NULL)
		(*r)->root = new;
	else if (t->parent->lchild == t)
		t->parent->lchild = new;
	else
		t->parent->rchild = new;
	new->rchild = t;
	t->parent = new;
}

void insertrbtree(rbroot** r, int key)
{
	rbtree* t = (*r)->root;
	rbtree* p = t;
	while (t != NULL)
	{
		p = t;
		if (key < t->data)
			t = t->lchild;
		else if (key > t->data)
			t = t->rchild;
		else
			return;
	}
	t = (rbtree*)malloc(sizeof(rbtree));
	t->data = key;
	t->color = red;
	t->lchild = t->rchild = NULL;
	t->parent = p;
	if ((*r)->root == NULL)
		(*r)->root = t;
	else if (key < p->data)
		p->lchild = t;
	else
		p->rchild = t;

	insert_rbtree(r, t);
}

void insert_rbtree(rbroot** r, rbtree* t)
{
	rbtree* brother;
	while (t->parent && t->parent->color == red)
	{
		if (t->parent == t->parent->parent->lchild)
		{
			brother = t->parent->parent->rchild;
			if (brother && brother->color == red)
			{
				t->parent->color = black;
				brother->color = black;
				t->parent->parent->color = red;	
				t = t->parent->parent;
			}
			else
			{
				if (t == t->parent->rchild)
				{
					t = t->parent;
					l_rotate(r, t);
				}
				else
				{
					t->parent->color = black;
					t->parent->parent->color = red;
					r_rotate(r, t->parent->parent);
				}
			}
		}
		else
		{
			brother = t->parent->parent->lchild;
			if (brother && brother->color == red)
			{
				t->parent->color = black;
				brother->color = black;
				t->parent->parent->color = red;
				t = t->parent->parent;
			}
			else
			{
				if (t == t->parent->lchild)
				{
					t = t->parent;
					r_rotate(r, t);
				}
				else
				{
					t->parent->color = black;
					t->parent->parent->color = red;
					l_rotate(r, t->parent->parent);
				}
			}
		}
	}
	(*r)->root->color = black;
}

void traverse(rbtree* t)
{
	if (t == NULL)
		return;
	traverse(t->lchild);
	printf("%d ", t->data);
	traverse(t->rchild);
}