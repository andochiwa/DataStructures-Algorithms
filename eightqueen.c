#include<stdio.h>

void eightqueen(int row);
int notdanger(int row, int cul);

int count = 0;
int chess[8][8] = { 0 };

int main(void)
{
	eightqueen(0);
	printf("总共有%d种解法", count);
	return 0;
}

void eightqueen(int row)
{
	int cul;
	if (row > 7)
	{
		int i, j;
		printf("打印第%d种结果", count + 1);
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
		if (notdanger(row, cul) == 1) //判断这行这列是否危险，不危险则让其放下为1，进行下一行测试
		{
			chess[row][cul] = 1;
			eightqueen(row + 1);

			chess[row][cul] = 0;      //结束，初始回0
		}
	}
}
int notdanger(int row, int col)
{
	int i, j;
	for (i = 0; i < 8; i++)							//判断列是否危险
	{
		if (chess[i][col] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 &&j >= 0; i--, j--) //左上
	{
		if (chess[i][j] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j < 8; i--, j++) //右上
	{
		if (chess[i][j] == 1)
			return 0;
	}
	return 1;
}