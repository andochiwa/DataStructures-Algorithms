#include<stdio.h>
#include<stdlib.h>

typedef struct circular_doublelist
{
	char data;
	struct doublelist* prior;
	struct doublelist* next;
}doublelist;

void initdoublelist(doublelist** p);
void show(doublelist* p,int x);

int main(void)
{
	doublelist* p = NULL;
	initdoublelist(&p);
	int x;
	printf("输入值:\n");
	scanf("%d", &x);
	show(p, x);
	return 0;
}

void initdoublelist(doublelist** p)
{
	doublelist* new;
	doublelist* target;
	for(int i = 0; i < 26;i++)
	{
		if (*p == NULL)
		{
			(*p) = (doublelist*)malloc(sizeof(doublelist));
			(*p)->data = 'A';
			(*p)->next = *p;
			(*p)->prior = *p;
		}
		else
		{
			for (target = *p; target->next != *p; target = target->next);
			new = (doublelist*)malloc(sizeof(doublelist));
			new->data = 'A' + i;
			new->next = *p;
			target->next = new;
			new->prior = target;
			(*p)->prior = new;
		}
	}
	
}

void show(doublelist* p, int x)
{
	int i;
	if (x >= 0)
	{

		for (i = 0; i < x; i++, p = p->next);
		for (int j = 0; j < 26; j++)
		{
			printf("%c", p->data);
			p = p->next;
		}
	}
	else
	{
		for (i = 0; i < abs(x); i++, p = p->prior);
		for (int j = 0; j < 26; j++)
		{
			printf("%c", p->data);
			p = p->next;
		}

	}

}