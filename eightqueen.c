#include<stdio.h>

void eightqueen(int row);
int notdanger(int row, int cul);

int count = 0;
int chess[8][8] = { 0 };

int main(void)
{
	eightqueen(0);
	printf("�ܹ���%d�ֽⷨ", count);
	return 0;
}

void eightqueen(int row)
{
	int cul;
	if (row > 7)
	{
		int i, j;
		printf("��ӡ��%d�ֽ��", count + 1);
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (chess[i][j] == 1)
					printf("1 ");
				else
					printf("0 ");
			}
			printf("\n");
		}
		printf("\n");
		count++;
		return;
	}
	for (cul = 0; cul < 8; cul++)
	{
		if (notdanger(row, cul) == 1) //�ж����������Ƿ�Σ�գ���Σ�����������Ϊ1��������һ�в���
		{
			chess[row][cul] = 1;
			eightqueen(row + 1);

			chess[row][cul] = 0;      //��������ʼ��0
		}
	}
}
int notdanger(int row, int col)
{
	int i, j;
	for (i = 0; i < 8; i++)							//�ж����Ƿ�Σ��
	{
		if (chess[i][col] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 &&j >= 0; i--, j--) //����
	{
		if (chess[i][j] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j < 8; i--, j++) //����
	{
		if (chess[i][j] == 1)
			return 0;
	}
	return 1;
}