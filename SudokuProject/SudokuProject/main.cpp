


/* 

#include "stdio.h"
#include "stdlib.h"

void main()
{
	printf("hello world");
	system("pause");
}

*/

#include <string.h>
#include <math.h>
#include <stdio.h>

int dfs(int x, int y);
bool judge(int i, int y, int num);
int a[9][9];
int main()
{
	int i, j;
	a[9][9] = {
		{4,0,0,0,8,0,0,0,0},
		{0,2,7,0,0,0,3,4,0},
		{8,9,0,4,0,7,0,1,5},
		{6,0,0,2,0,5,0,0,9},
		{0,8,0,0,0,0,0,3,0},
		{2,0,0,8,0,9,0,0,4},
		{1,4,0,7,0,6,0,9,3},
		{0,6,5,0,0,0,2,7,0},
		{0,0,0,0,9,0,0,0,0}
	};
	dfs(0, 0);
	return 0;
}


int dfs(int x, int y)
{
	int i;
	if (x == 9)
	{
		for (i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				printf("%d", a[i][j]);
			printf("\n");
		}
	}

	if (a[x][y] == 0)
	{
		for(i=1;i<=9;i++)
	}



}



