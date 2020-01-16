#include<stdio.h>
int main()
{
	int x,left=0,right=5,f=0;
	int mid;
	int a[10] = {1,3,5,7,9,10,11,13,15,19};//定义一个数组
	printf("请输入查找的数：");
	scanf("%d",&x);//输入所需查找的数
	while(f==0 && left<=right)//判断数组左右大小
	{
		mid=(left+right)/2;//取二分中间值
		if (x==a[mid])   //若输入的数等于中间值
			f=1;
		else if(x<a[mid])//若输入的数比中间值小
			right=mid-1;
		else             //若输入的数比中间值大
			left=mid+1;
	}
	if(f==0)
		printf("没有找到/n");
	else
		printf("该数所在在位置为：%d\n",mid+1);
}

