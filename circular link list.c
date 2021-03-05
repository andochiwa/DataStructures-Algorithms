#include<stdio.h>
#include<stdlib.h>
//ѭ�������ͷ�����ֵ

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
	printf("�ڼ���λ�ò���ʲô:\n");
	scanf("%d %d", &i, &val);
	insert(&p, i, val);
	show(p);
	return 0;
}

void initlist(list** p)
{
	int val;
	list* new;
	list* target;   //Ѱ��β���
	printf("����ڵ��ֵ����0����"); //�������Ϊ�գ��򴴽�һ������ָ����ָ���Լ�������Ѱ��β�ڵ�
	      					         //��β�ڵ��ָ����ָ������½ڵ㣬�½ڵ��ָ����ָ��ͷ���
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
			for (target = *p; target->next != *p; target = target->next); //Ѱ��β���

			new = (list*)malloc(sizeof(list));
			if (new == NULL)
				return exit(0);
			new->data = val;
			new->next = *p; //�½ڵ�ָ��ͷ���
			target->next = new; //β���ָ���½ڵ�
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
	if (i == 1)    //����ͷ��㣬��Ҫ���⴦��
	{              //��Ҫ�ҵ�β��㣬��β���ָ���½�㣬�½��ָ��ͷ���
		for (target = p; target->next != p; target = target->next);

		new = (list*)malloc(sizeof(list));
		if (new == NULL)
			exit(0);
		new->data = val;
		target->next = new;
		new->next = *p;
		*p = new;    //��Ϊ�ǲ���ͷ��㣬����Ҫ���½ڵ��Ϊͷ���
	}
	else //������λ�ò����㣬�����㳤�ȳ�����������β������
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