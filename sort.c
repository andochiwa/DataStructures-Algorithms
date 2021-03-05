#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#define SIZE 1000
#define BUCKETSIZE 32768

typedef struct queuelist
{
	int data;
	struct queuelist* next;
}queuelist;

typedef struct queue
{
	queuelist* front, * rear;
}queue;

typedef struct
{
	int* base, * top;
	int count;
}stack;

void initlist(queuelist** p);
void insert_sort(queuelist** p, int e);
void delete_sort(queuelist** p, int* e);
void initstack(stack* s);
void push(stack* s, int e);
void pop(stack* s, int* e);
void bubblesort(int* a);
void selectsort(int* a);
void straightsort(int* a);
void shellsort(int* a);
void heapsort(int* a);
void heapadjust(int* a, int i, int size);

void mergesort(int* a);
void msort(int* a, int start, int end);
void merge(int* a, int start, int mid, int end);

void merge_sort(int* a);

void quicksort(int* a);
void Qsort(int* a, int low, int high);

void quick_sort(int* a);

void bucketsort(int* a);

void initqueue(queue* q);
void enqueue(queue* q, int e);
void dequeue(queue* q, int* e);
int getmax(int* a);
void radixsort(int* a);


int main(void)
{
	clock_t start, finish;
	srand((unsigned)time(NULL));
	int a[SIZE];
	int b[SIZE];
	memcpy(b, a, sizeof(a));
	int i;
	for (i = 0; i < SIZE; i++)
	{
		a[i] = rand();
	}
	/*for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
	/*memcpy(b, a, sizeof(a));
	start = clock();
	bubblesort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	selectsort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	straightsort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);*/
	memcpy(b, a, sizeof(a));
	start = clock();
	shellsort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	int c[] = {9, 44, 3, 32, 93, 57, 29, 12, 37, 80,62, 20};
	heapsort(c);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	merge_sort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	quicksort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	quick_sort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	radixsort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	bucketsort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	memcpy(b, a, sizeof(a));
	start = clock();
	mergesort(b);
	finish = clock();
	printf("时间:%f\n", (double)((double)finish - (double)start) / CLOCKS_PER_SEC);
	return 0;
}

void bubblesort(int* a)
{
	int i, j;
	int flag = true;
	for (i = 0; i < SIZE - 1 && flag; i++)
	{
		flag = false;
		for (j = 0; j < SIZE - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = true;
			}
		}
	}
	printf("冒泡排序:\n");
	/*for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void selectsort(int* a)
{
	int i, j;
	int min;
	for (i = 0; i < SIZE - 1; i++)
	{
		min = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	printf("选择排序:\n");
	/*for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void straightsort(int* a)
{
	int i, j;
	int temp;
	for (i = 1; i < SIZE; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
	printf("插入排序:\n");
	/*for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void shellsort(int* a)
{
	int i, j, k, temp;
	int gap;
	for (gap = SIZE / 2; gap > 0; gap = gap / 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < SIZE; j += gap)
			{
				temp = a[j];
				for (k = j - gap; k >= 0 && a[k] > temp; k -= gap)
				{
					a[k + gap] = a[k];
				}
				a[k + gap] = temp;
			}
		}
	}
	printf("希尔排序:\n");
	/*for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void heapsort(int* a)
{
	int i, temp;
	for (i = SIZE / 2 - 1; i >= 0; i--)
	{
		heapadjust(a, i, SIZE - 1);
	}
	for (i = SIZE - 1; i > 0; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapadjust(a, 0, i - 1);
	}
	printf("堆排序:\n");
	/*for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void heapadjust(int* a, int i, int size)
{
	int j, temp;
	temp = a[i];
	for (j = 2 * i + 1; j <= size; j = j * 2 + 1)
	{
		if (j != size)
		{
			if (a[j] < a[j + 1])
				j++;
		}
		if (temp > a[j])
			break;
		a[i] = a[j];
		i = j;
	}
	a[i] = temp;
}

void mergesort(int* a)
{
	msort(a, 0, SIZE - 1);
	printf("归并排序:\n");
	/*for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void msort(int* a,int start, int end)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	msort(a, start, mid);
	msort(a, mid + 1, end);
	merge(a, start, mid, end);
}

void merge(int* a, int start, int mid, int end)
{
	int temp[SIZE];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	for (j = 0, i = start; j < k; i++, j++)
	{
		a[i] = temp[j];
	}
}

void merge_sort(int* a)
{
	int i, left_min, left_max, right_min, right_max, next;
	int* temp = (int*)malloc(sizeof(int) * SIZE);
	for (i = 1; i < SIZE; i *= 2)
	{
		for (left_min = 0; left_min < SIZE - 1; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = right_min + i;
			if (right_max > SIZE)
				right_max = SIZE;
			next = 0;
			while (left_min < left_max && right_min < right_max)
			{
				if (a[left_min] < a[right_min])
					temp[next++] = a[left_min++];
				else
					temp[next++] = a[right_min++];
			}
			while (left_min < left_max)
			{
				a[--right_min] = a[--left_max];
			}
			while (next > 0)
			{
				a[--right_min] = temp[--next];
			}
		}
	}
	printf("归并非递归排序?:\n");
	/*for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void quicksort(int* a)
{
	Qsort(a, 0, SIZE - 1);
	printf("快速排序:\n");
	/*for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void Qsort(int* a, int low, int high)
{
	if (low < high)
	{
		int l = low, h = high, pivot = a[low];
		while (l < h)
		{
			while (l < h && a[h] >= pivot)
				h--;
			a[l] = a[h];
			while (l < h && a[l] <= pivot)
				l++;
			a[h] = a[l];
		}
		a[l] = pivot;
		Qsort(a, low, l - 1);
		Qsort(a, l + 1, high);
	}
}

void initstack(stack* s)
{
	s->base = (int*)malloc(sizeof(int) * SIZE);
	s->top = s->base;
	s->count = 0;
}

void push(stack* s, int e)
{
	*(s->top) = e;
	s->top++;
	s->count++;
}

void pop(stack* s, int* e)
{
	if (0 == s->count)
		return;
	s->top--;
	(*e) = *(s->top);
	s->count--;
}

void quick_sort(int* a)
{
	int left = 0, right = SIZE - 1;
	stack s;
	int l, r, pivot;
	initstack(&s);
	push(&s, left);
	push(&s, right);
	while (s.count != 0)
	{
		pop(&s, &right);
		pop(&s, &left);
		l = left, r = right, pivot = a[left];
		while (l < r)
		{
			while (l < r && a[r] >= pivot)
				r--;
			a[l] = a[r];
			while (l < r && a[l] <= pivot)
				l++;
			a[r] = a[l];
		}
		a[l] = pivot;
		if (left < l - 1)
		{
			push(&s, left);
			push(&s, l - 1);
		}
		if (right > l + 1)
		{
			push(&s, l + 1);
			push(&s, right);
		}
	}
	printf("快速非递归排序:\n");
	/*for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
}

void radixsort(int* a)
{
	int i, j, k, length, radixvalue, digit;
	queue bucket[10];
	int new;
	for (i = 0; i < 10; i++)
	{
		initqueue(&bucket[i]);
	}
	length = getmax(a);
	digit = 1;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			radixvalue = (a[j] / digit) % 10;
			new = a[j];
			enqueue(&bucket[radixvalue], new);
		}
		digit *= 10;
		k = 0;
		for (j = 0; j < 10; j++)
		{
			while (bucket[j].front->next != NULL)
				dequeue(&bucket[j], &a[k++]);
		}
	}
	printf("基数排序:\n");
}

int getmax(int* a)
{
	int max = a[0];
	int i;
	for (i = 1; i < SIZE; i++)
		if (a[i] > max)
			max = a[i];
	int sizemax = 1;
	while ((max = max / 10) != 0)
		sizemax++;
	return sizemax;
}

void initqueue(queue* q)
{
	q->front = (queuelist*)malloc(sizeof(queuelist));
	q->front->next = NULL;
	q->rear = q->front;
}

void enqueue(queue* q, int e)
{
	queuelist* new = (queuelist*)malloc(sizeof(queuelist));
	new->data = e;
	new->next = NULL;
	q->rear->next = new;
	q->rear = new;
}

void dequeue(queue* q, int* e)
{
	if (q->front->next == q->rear)
	{
		(*e) = q->rear->data;
		free(q->rear);
		q->front->next = NULL;
		q->rear = q->front;
	}
	else
	{
		queuelist* new = q->front->next;
		(*e) = new->data;
		q->front->next = new->next;
		free(new);
	}
}

void initlist(queuelist** p)
{
	*p = (queuelist*)malloc(sizeof(queuelist));
	(*p)->next = NULL;
}

void insert_sort(queuelist** p, int e)
{
	queuelist* head = *p;
	queuelist* new = (queuelist*)malloc(sizeof(queuelist));
	new->data = e;
	while (head->next != NULL && head->next->data < new->data)
		head = head->next;
	new->next = head->next;
	head->next = new;
}

void delete_sort(queuelist** p, int* e)
{
	queuelist* new = (*p)->next;
	(*p)->next = new->next;
	(*e) = new->data;
	free(new);
}

void bucketsort(int* a)
{
	queuelist* bucket[BUCKETSIZE];			
	int i, j, bucketvalue;
	for (i = 0; i < BUCKETSIZE; i++)
	{
		initlist(&bucket[i]);
	}
	for (i = 0; i < SIZE; i++)
	{
		bucketvalue = a[i] * BUCKETSIZE / 32768;		
		insert_sort(&bucket[bucketvalue], a[i]);	
	}
	j = 0;
	for (i = 0; i < BUCKETSIZE; i++)						
	{
		while (bucket[i]->next != NULL)
			delete_sort(&bucket[i], &a[j++]);
	}
	printf("桶排序:\n");
}