

#include <stdio.h>  
#include <time.h>  
#include <math.h>
#include <stdlib.h>


//检查是否符合数独的约束条件
bool check(int sudoku[][9], int i, int j);

//输出数独
void printSudoku(int sudoku[][9]);


int main(int argc,char *argv[])
{
	
	int T;
	for(T=0;T<argc;T++)
	printf("%d",argv[T]);
	int N = 2;;
	int sudoku[9][9] = { 0 };
	int i, j, temp = 0;
	int k = 0, num = 0;

	
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++)
			sudoku[i][j] = 0;
	sudoku[0][0]=3; 
	
	
	/*回溯法，构造数独矩阵*/
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
			else if (check(sudoku, i, j) == 1)
			{
				++k;
				break;
			}
		}

		if (k == 81)
		{
			printf("Proper sudoku matrix %d: \n", ++num);
		//	printSudoku(sudoku);
			if (num >= N)
				return 0;

			--k;
		}
	}
	system("pause");
	return 0;
}



bool check(int sudoku[][9], int i, int j)
{
	int value = sudoku[i][j];
	int p, q;
	int m, n;

	for (p = 0; p<9; p++)
		if (p != i && sudoku[p][j] == value)
			return false;
	for (p = 0; p<9; p++)
		if (p != j && sudoku[i][p] == value)
			return false;

	p = i / 3;
	q = j / 3;
	for (m = p * 3; m<p * 3 + 3; m++)
		for (n = q * 3; n<q * 3 + 3; n++)
			if (m != i && n != j && sudoku[m][n] == value)
				return false;

	return true;
}


void printSudoku(int sudoku[][9])
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
			printf("%4d", sudoku[i][j]);
		printf("\n");
	}
}
