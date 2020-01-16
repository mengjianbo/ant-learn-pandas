#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define EQUAL	1	//EQUAL表示c[i][j]是由c[i-1][j-1]+1来的=====此时两个序列有相同的字符
#define UP		2	//UP表示c[i][j]是由c[i-1][j]来的============此时两个序列没有相同的字符
#define LEFT	3	//LEFT表示c[i][j]是由[ci][j-1]来的==========此时两个序列没有相同的字符
 
int Lcs_length( char *str1, char *str2, int **c, int **b)//最长公共子序列长度函数
{
	int len1 = strlen(str1),
		len2 = strlen(str2);
	int i,j;
	for( i = 1; i <= len1; i++)
		c[i][0] = 0;
	for ( j = 0; j <= len2; j++)
		c[0][j] = 0;
	for(  i = 1; i <= len1; i++)
		for( j = 1; j <= len2; j++)
		{	
			/*******************************
			使用i-1和j-1
			算法导论书上写的是比较str1[i]和str[j]，但是算法导论书上的两个序列下标是由1开始的
			这里使用i-1以及j-1是由于数组的下标从0开始
			********************************/
			if( str1[i-1] == str2[j-1] )											
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = EQUAL; 
			}
			else if (c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = UP;
				}
			else 
				{
					c[i][j] = c[i][j-1];
					b[i][j] = LEFT;
				}
		}
		return c[len1][len2];
}
 

void Print_Lcs( char *str, int **b, int i, int j)//打印函数，输出字符串1和字符串2的最长公共子序列
{
	if( i == 0 || j == 0)
		return;
	if( b[i][j] == EQUAL)
	{
		Print_Lcs(str, b, i - 1, j - 1);
		printf("%c ", str[i-1]);
	}
	else if ( b[i][j] == UP )
		Print_Lcs(str, b, i - 1, j);
	else 
		Print_Lcs(str, b, i , j - 1);
}

void Find_Lcs( char *str1, char *str2)//寻找最长公共子序列函数
{
	int i,j,length;
	int len1 = strlen(str1),
		len2 = strlen(str2);
	
	int **c = (int **)malloc(sizeof(int*) * (len1 + 1));//申请b和c二维数组
	int **b = (int **)malloc(sizeof(int*) * (len1 + 1));
	for( i = 0; i<= len1; i++ )	
	{
		c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
		b[i] = (int *)malloc(sizeof(int) * (len2 + 1));
	}
 
	
	for ( i = 0; i<= len1; i++) //将二维数组b[][]和c[][]初始化为0
		for( j = 0; j <= len2; j++)
		{
			c[i][j] = 0;
			b[i][j] = 0;
		}
	

	length = Lcs_length(str1, str2, c, b);	//计算LCS的长度
	printf("\n最长公共子序列个数为：%d\n", length);
	
	
	printf("最长公共子序列为: ");//利用数组b输出最长子序列
	Print_Lcs(str1, b, len1, len2);
	printf("\n");
 
	
	for ( i = 0; i <= len1; i++)//动态内存释放
	{
		free(c[i]);
		free(b[i]);
	}
	free(c);
	free(b);
}
 
int main()
{
	char x[10] = "abcdefghi"; //输入第一串字符
	char y[10] = "bdegihbjk"; //输入第二串字符


	printf("第一串字符为：");//显示第一串字符
	for(int i=0;i<10;i++)   
	{
		printf("%c",x[i]);
	}

	printf("\n第二串字符为：");//显示第一串字符
	for(int j=0;j<10;j++)
	{
		printf("%c",x[j]);
	}

	Find_Lcs(x,y);  //调用函数查找最长公共子序列
	system("pause");
}
