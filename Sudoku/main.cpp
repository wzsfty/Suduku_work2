#include <stdio.h>    
#include <stdlib.h>
#include <string.h>
  

  
//检查是否符合数独的约束条件 
bool check(int sudoku[][9], int i, int j) ;



//验证参数输入
bool checkInput(int argc,char *argv1, char *argv2);
  
  
int main(int argc,char *argv[])
{  
	
	int N=0;
	if( checkInput(argc,argv[1],argv[2])==false  )
	{
		return 0;
	}else{
		N=atoi(argv[2]);
	}
    int sudoku[9][9] = {0};  
    int i, j ;  
    int k=0, num=0;  
  

    for(i=0; i<9; i++)  
        for(j=0; j<9; j++)  
            sudoku[i][j] = 0;  
 	sudoku[0][0]=3;

	FILE *fp;
	fp=fopen("../BIN/suduku.txt","w");
   //回溯 
    while(true)  
    {  
        i = k/9;  
        j = k%9;  
  
        while(true)  
        {  
            sudoku[i][j]++;  
            if(sudoku[i][j] == 10)  
            {  
                sudoku[i][j] = 0;  
                --k;  
                break;  
            }  
            else if(check(sudoku, i, j) == 1)  
            {  
                ++k;  
                break;  
            }  
        }  
  

		if(k == 81)  
        {  
			++num; 

			
			int ii,jj;
			for(ii=0;ii<9;ii++)
			{
				
				for(jj=0;jj<9;jj++)
					fprintf(fp,"%2d",sudoku[ii][jj]);
			fprintf(fp,"\n");
			
			}
			fprintf(fp,"\n");
            if(num >= N)  
                return 0;  
  
            --k;  
        }   
        
    }  
    fclose(fp);
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



bool checkInput(int argc,char *argv1, char *argv2)
{
	if(argc==3)
	{
		if(strcmp(argv1 ,"-c")==0)
		{
			for(int i=0;i<strlen(argv2);i++)
			if(argv2[i]<'0' || argv2[i]>'9')
			{
				printf("您输入的数独矩阵数目有误，请重新运行");
				return false;
			}
			return true;
		}else{
			printf("您输入的命令有误，请重新运行");
		}
	}else{
		printf("您输入参数有误，请重新运行");
	}
}
