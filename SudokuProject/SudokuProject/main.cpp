

/*
#include <cstdio>

#define SUDUKU_Num 2

bool check(int sudoku[][9], int i, int j)
{
	int value = sudoku[i][j];
	int p, q;
	int m, n;

	//���������û���ظ�
	for (p = 0; p < 9; p++)
		if (p != i && sudoku[p][j] == value)
			return false;
	//��
	for (p = 0; p < 9; p++)
		if (p != j && sudoku[i][p] == value)
			return false;

	p = i / 3;
	q = j / 3;
	for (m = p * 3; m < p * 3 + 3; m++)
		for (n = q*#; n < q * 3 + 3; n++)
			if (m != i && n != j && sudoku[m][n] == value)
				return false;

	return true;
}

void print_sudoku(int sudoku[][9])
{
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			printf("%d", sudoku[i][j]);
	printf("\n");
}

int main()
{
	int sudoku[9][9] = { 0 };
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			sudoku[i][j] = 0;

	return 0;
}
*/

#include <stdio.h>  
#include <time.h>  
#include <math.h>
#include <stdlib.h>

/*Ҫ���ɵ������������*/
#define SUDOKU_NUM 10000

/**
* ����is_digital_match
* ���sudoku[i][j]�ϵ�ֵ�Ƿ����Ҫ��
*/
int is_digital_match(int sudoku[][9], int i, int j)
{
	int temp = sudoku[i][j];
	int p, q;
	int m, n;

	for (p = 0; p<9; p++)
		if (p != i && sudoku[p][j] == temp)
			return 0;
	for (p = 0; p<9; p++)
		if (p != j && sudoku[i][p] == temp)
			return 0;

	p = i / 3;
	q = j / 3;
	for (m = p * 3; m<p * 3 + 3; m++)
		for (n = q * 3; n<q * 3 + 3; n++)
			if (m != i && n != j && sudoku[m][n] == temp)
				return 0;

	return 1;
}

/*�����������*/
void sudoku_print(int sudoku[][9])
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
			printf("%4d", sudoku[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int sudoku[9][9] = { 0 };
	int i, j, temp = 0;
	int k = 0, num = 0;

	
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++)
			sudoku[i][j] = 0;
	/*ͨ�����һЩ����ԣ���ÿ�����ɲ�ͬ����������*/
	/*��Ӹ�������ԣ������ɵľ��󽫸��漴*/
	/* 
	for (i = 0; i<9; i++)
	{
		temp = rand() % 81;
		sudoku[temp / 9][temp % 9] = i + 1;
	} 
	*/
	sudoku[0][0]=3; 
	/*���ݷ���������������*/
	while (1)
	{
		i = k / 9;
		j = k % 9;

		while (1)
		{
			sudoku[i][j]++;
			if (sudoku[i][j] == 10)
			{
				sudoku[i][j] = 0;
				--k;
				break;
			}
			else if (is_digital_match(sudoku, i, j) == 1)
			{
				++k;
				break;
			}
		}

		if (k == 81)
		{
			printf("Proper sudoku matrix %d: \n", ++num);
			sudoku_print(sudoku);
			if (num >= SUDOKU_NUM)
				return 0;

			--k;
		}
	}
	system("pause");
	return 0;
}
