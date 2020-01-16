#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define EQUAL	1	//EQUAL��ʾc[i][j]����c[i-1][j-1]+1����=====��ʱ������������ͬ���ַ�
#define UP		2	//UP��ʾc[i][j]����c[i-1][j]����============��ʱ��������û����ͬ���ַ�
#define LEFT	3	//LEFT��ʾc[i][j]����[ci][j-1]����==========��ʱ��������û����ͬ���ַ�
 
int Lcs_length( char *str1, char *str2, int **c, int **b)//����������г��Ⱥ���
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
			ʹ��i-1��j-1
			�㷨��������д���ǱȽ�str1[i]��str[j]�������㷨�������ϵ����������±�����1��ʼ��
			����ʹ��i-1�Լ�j-1������������±��0��ʼ
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
 

void Print_Lcs( char *str, int **b, int i, int j)//��ӡ����������ַ���1���ַ���2�������������
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

void Find_Lcs( char *str1, char *str2)//Ѱ������������к���
{
	int i,j,length;
	int len1 = strlen(str1),
		len2 = strlen(str2);
	
	int **c = (int **)malloc(sizeof(int*) * (len1 + 1));//����b��c��ά����
	int **b = (int **)malloc(sizeof(int*) * (len1 + 1));
	for( i = 0; i<= len1; i++ )	
	{
		c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
		b[i] = (int *)malloc(sizeof(int) * (len2 + 1));
	}
 
	
	for ( i = 0; i<= len1; i++) //����ά����b[][]��c[][]��ʼ��Ϊ0
		for( j = 0; j <= len2; j++)
		{
			c[i][j] = 0;
			b[i][j] = 0;
		}
	

	length = Lcs_length(str1, str2, c, b);	//����LCS�ĳ���
	printf("\n����������и���Ϊ��%d\n", length);
	
	
	printf("�����������Ϊ: ");//��������b����������
	Print_Lcs(str1, b, len1, len2);
	printf("\n");
 
	
	for ( i = 0; i <= len1; i++)//��̬�ڴ��ͷ�
	{
		free(c[i]);
		free(b[i]);
	}
	free(c);
	free(b);
}
 
int main()
{
	char x[10] = "abcdefghi"; //�����һ���ַ�
	char y[10] = "bdegihbjk"; //����ڶ����ַ�


	printf("��һ���ַ�Ϊ��");//��ʾ��һ���ַ�
	for(int i=0;i<10;i++)   
	{
		printf("%c",x[i]);
	}

	printf("\n�ڶ����ַ�Ϊ��");//��ʾ��һ���ַ�
	for(int j=0;j<10;j++)
	{
		printf("%c",x[j]);
	}

	Find_Lcs(x,y);  //���ú������������������
	system("pause");
}
