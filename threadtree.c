#include<stdio.h>

typedef char elemtype;
typedef enum { link, thread } pointertag;

typedef struct bithitree
{
	elemtype data;
	struct bithitree* lchild,* rchild;
	pointertag ltag, rtag;
}bithitree;

void createbithitree(bithitree** T);
void inthreading(bithitree* T);
void traversalbithitree(bithitree* T);

bithitree* pre = NULL;

int main(void)
{
	bithitree* tree = NULL;
	createbithitree(&tree);
	inthreading(tree);
	traversalbithitree(tree);
	return 0;
}

void createbithitree(bithitree** T) //前序创建二叉树
{
	char c;
	scanf("%c", &c);
	if (c == '#')
		*T = NULL;
	else
	{
		*T = (bithitree*)malloc(sizeof(bithitree));
		(*T)->data = c;
		(*T)->ltag = link;
		(*T)->rtag = link;
		createbithitree(&(*T)->lchild);
		createbithitree(&(*T)->rchild);
	}
}

void inthreading(bithitree* T) //中序二叉树线索化
{
	if (T != NULL)
	{
		inthreading(T->lchild);
		if (T->lchild == NULL)
		{
			T->ltag = thread;
			T->lchild = pre;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rtag = thread;
			pre->rchild = T;
		}
		pre = T;

		inthreading(T->rchild);
	}
}


void traversalbithitree(bithitree* T) //遍历二叉树
{
	while (T != NULL)
	{
		while (T->ltag == link)
			T = T->lchild;
		printf("%c", T->data);
		while (T->rtag != link && T->rchild != NULL)
		{
			T = T->rchild;
			printf("%c", T->data);
		}
		T = T->rchild;
	}
}
