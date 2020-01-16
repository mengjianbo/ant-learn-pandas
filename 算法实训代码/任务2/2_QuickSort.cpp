#include <stdio.h>
#include <stdlib.h>
void QuickSort(int a[],int left,int right) //快速排序函数
{	
	int i = left;//定义左右指针指向数组的下标
	int j = right;
	if(i>j)      //判断左右数值大小，递归出口
		return;
	int p = a[i];//记录标杆值
	while(i<j)//一次循环可以得到：标杆的左侧都比标杆小，标杆的右侧都比标杆大
	{
		while(i<j && a[j] >= p)//从右边开始找比标杆小的为止
			j--;
		a[i] = a[j];//将较小的数赋值到左边
		while(i<j && a[i] <= p)//从左边开始找比标杆大的为止
			i++;
		a[j] = a[i];//将较大的数赋值到右边
	}
	a[i] = p;//将标杆值补到数组中
	//一次循环完成
	QuickSort(a,left,i-1); //进行左侧递归
	QuickSort(a,i+1,right);//进行右侧递归
} 

void sort(int a[],size_t len)//调用快速排序 
{
	QuickSort(a,0,len-1);
}


void main()
{
	int a[10]={9,5,7,6,1,3,4,8,11,2};

	printf("原数列为：\n");//输出原数列
	for(int i=0;i<10;i++)
	{  
        printf("%d ",a[i]);  
    } 
	
	sort(a,10);//调用排序函数

	printf("\n排序后数列为：\n");//输出排序后的数列
		for(int j=0;j<10;j++)
	{  
        printf("%d ",a[j]);  
    }
	printf("\n");

}




















/*
void show(int a[],int len)//输出
{
	for(int i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
}


//show(a,10);*/