#include <stdio.h>
#include <string>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
//每次将数组划分为两部分，再在满足条件的一部分里找到第k小的数，它前面的数就是最小的k个数
void FindKLeastNums(int Data[],int lower,int upper,int Least_Size)//找最小数的函数
{
	if(Least_Size<lower||Least_Size>upper)
		return;
	int i = lower;int j = upper + 1;int Tmp;
	while (1)
	{
		do 
		{
			i++;
		} while (i<upper && Data[i]<Data[lower]);
	    do 
	    {
			j--;
	    } while (Data[j]>Data[lower]);
		if (i>j)
		  break;
		Tmp = Data[i];
		Data[i] = Data[j];
		Data[j] = Tmp;
	}
	Tmp = Data[lower];
	Data[lower] = Data[j];
	Data[j] = Tmp;
	if (j<Least_Size)
	{
		FindKLeastNums(Data,j+1,upper,Least_Size);
	}
	else if (j>Least_Size)
	{
		FindKLeastNums(Data,lower,j-1,Least_Size);
	}
	return;
}
 
int main(void)
{
	int k;
	int i = 0;
	int data[10] = {1,3,5,2,6,8,4,9,0,7};

	printf("原数列为："); //输出原数列
	while(i<10)
	{
		printf("%d ",data[i]);
		i++;
	}

	FindKLeastNums(data,0,9,3);

	printf("\n请输入所需查找最小数的个数k：");//输入所需查找最小数的个数
	scanf("%d",&k);

	printf("最小的%d个数为:",k);//输出最小数
    for (i = 0;i<k;i++)    
    {
		printf("%d ",data[i]);
    }
	printf("\n");
    return 0;
}