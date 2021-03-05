#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int kmp(char* t, char* p);
void getnext(char* c,int* next);


int main(void)
{
	char* t, * p;
	t = (char*)malloc(sizeof(char) * 15);
	p = (char*)malloc(sizeof(char) * 15);
	printf("输入串t:\n");
	scanf("%s", t);
	printf("输入串p:\n");
	scanf("%s", p);
	printf("匹配为%d", kmp(t, p));
	return 0;
}

int kmp(char* t, char* p)
{
	int i = 0;
	int j = 0;
	int n1 = strlen(t), n2 = strlen(p);
	int next[n2];
	getnext(p,next);
	while (i < n1 && j < n2)
	{
		if (j == -1 || t[i] == p[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j == n2)
		return i - j;
	else
		return -1;
}

void getnext(char* p, int* next)
{
	int i = 0;
	int j = -1;
	next[0] = -1;
	int n = strlen(p);
	while (i < n - 1)
	{
		if (j == -1 || p[i] == p[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}