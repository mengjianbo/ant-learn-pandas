#include<stdio.h>
#include<iostream>
using namespace std;
int a[100] = {1,3,5,7,9,10,11,13,15,19};//数组中的数（由小到大）
int k;//要找的数字
int BinarySearch(int right,int left)//二分查找函数
{
    int mid = (right+left)/2;//定义一个中间值，便于把数组均匀分为左右两边
    if(right>left)//查找完毕没有找到答案，返回-1
        return -1;
    else
    {
        if(a[mid] == k)
            return mid;//找到并返回位置.
        else if(a[mid]>k) //所找数小于中间值
            return BinarySearch(right,mid-1);//找左边
         else
            return BinarySearch(mid+1,left);//找右边
    }
}
int main()
{
	printf("请输入查找的数：");//输入要查找的数
	scanf("%d",&k);
	printf("该数所在在位置为：");
	cout<<BinarySearch(0,9)+1;//从数组a[0]到a[9]
	printf("\n");
	return 0;
}






        //cin>>k;//输入要找的数字c语言把cin换为scanf即可