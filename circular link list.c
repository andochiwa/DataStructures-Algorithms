#include<stdio.h>
#include<stdlib.h>
//循环链表的头结点有值

typedef struct circularlist
{
	int data;
	struct circularlist* next;
}list;

void initlist(list** p);
void show(list* p);
void insert(list** p, int i, int val);

int main(void)
{
	int i, val;
	list* p = NULL;
	initlist(&p);
	show(p);
	printf("第几个位置插入什么:\n");
	scanf("%d %d", &i, &val);
	insert(&p, i, val);
	show(p);
	return 0;
}

void initlist(list** p)
{
	int val;
	list* new;
	list* target;   //寻找尾结点
	printf("输入节点的值，按0返回"); //如果链表为空，则创建一个链表，指针域指向自己，否则寻找尾节点
	      					         //将尾节点的指针域指向这个新节点，新节点的指针域指向头结点
	while (1)
	{
		scanf("%d", &val);
		if (val == 0)
			return;
		if (*p == NULL)
		{
			*p = (list*)malloc(sizeof(list));
			if (*p == NULL)
				exit(0);
			(*p)->data = val;
			(*p)->next = *p;
		}
		else
		{
			for (target = *p; target->next != *p; target = target->next); //寻找尾结点

			new = (list*)malloc(sizeof(list));
			if (new == NULL)
				return exit(0);
			new->data = val;
			new->next = *p; //新节点指向头结点
			target->next = new; //尾结点指向新节点
		}
	}
}

void show(list* p)
{
	list* new;
	new = p;
	do
	{
		printf("%d", new->data);
		new = new->next;
	} while (new != p);
	printf("\n");
}

void insert(list** p, int i, int val)
{
	list* new, * target;
	int j;
	if (i == 1)    //插入头结点，需要特殊处理
	{              //需要找到尾结点，让尾结点指向新结点，新结点指向头结点
		for (target = p; target->next != p; target = target->next);

		new = (list*)malloc(sizeof(list));
		if (new == NULL)
			exit(0);
		new->data = val;
		target->next = new;
		new->next = *p;
		*p = new;    //因为是插入头结点，所以要把新节点变为头结点
	}
	else //在其他位置插入结点，如果结点长度超过链表，则在尾部插入
	{   
		for (j = 1, target = *p; target->next != *p && j != i; target = target->next, j++);
			new = (list*)malloc(sizeof(list));
			if (new == NULL)
				exit(0);
			new->data = val;
			new->next = target->next;
			target->next = new;
	}
}