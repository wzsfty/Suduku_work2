


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
#include "stdlib.h"


int dfs(int x, int y);
bool judge(int i, int y, int num);
int a[9][9]= { 
{ 4,0,0,0,8,0,0,0,0 },
{ 0,2,7,0,0,0,3,4,0 },
{ 8,9,0,4,0,7,0,1,5 },
{ 6,0,0,2,0,5,0,0,9 },
{ 0,8,0,0,0,0,0,3,0 },
{ 2,0,0,8,0,9,0,0,4 },
{ 1,4,0,7,0,6,0,9,3 },
{ 0,6,5,0,0,0,2,7,0 },
{ 0,0,0,0,9,0,0,0,0 } 
};


int main()
{
	dfs(0, 0);

	system("pause");
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
		
		return 0;
	}

	if (a[x][y] == 0)//填数
	{
		for (i = 1; i <= 9; i++)
		{
			if (judge(x, y, i))
			{
				a[x][y] = i;
				dfs(x + (y + 1) / 9, (y + 1) % 9);
			}
		}
		a[x][y] = 0;//回溯
	}
	else 
		dfs(x + (y + 1) / 9, (y + 1) % 9);
	return 0;
}

bool judge(int i, int j, int num)
{
	int x, y, k, t;
	//找到纵向第几个方块
	if (i < 3) y = 0;
	else if (i < 6) y = 1;
	else y = 2;

	//找到横向第几个方块
	if (j < 3) x = 0;
	else if (j < 6) x = 1;
	else x = 2;

	//判断一行/一列是否有重复
	for (k = 0; k < 9; k++)
		if (a[i][k] == num && k != j)  return false;
	for (k = 0; k < 9; k++)
		if (a[k][j] == num && k != i) return false;
	for (k = y * 3; k < y * 3 + 3; k++)
		for (t = x * 3; t < x * 3 + 3; t++)
			if (a[k][t] == num && k != i && t != j)
				return false;
	return true;
}



