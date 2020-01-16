#include<iostream>  
#include<cstdio>  
  
void MergeSort(int s[],int t[],int b,int mid,int e){//将s[b...mid]与s[mid+1...e]合并函数
    int i=b;//i->前一个块(左序列的首数值)  
    int j=mid+1;//j->后一个块(右序列的首数值)
    int k=0;//k->t数组  
    while(i<=mid && j<=e)
	{  
        if(s[i]<=s[j])t[k++]=s[i++];  
        else t[k++]=s[j++];  
    }  
    while(i<=mid){  
        t[k++]=s[i++];  
    }  
    while(j<=e){  
        t[k++]=s[j++];  
    }  
    for(i=0;i<k;i++){  //每次都把序数组t的值赋回给s，这样s对于区间[b,e]也是有序的
        s[b+i]=t[i];  
    }  
}  
  
  
void MSort(int s[],int t[],int b,int e)//排序函数
{  
    if(b<e)
	{  
        int mid;  
        mid=(b+e)/2;  //定义一个中间值,以便于分为左右两序列
        MSort(s,t,b,mid);      //对左边进行排序
        MSort(s,t,mid+1,e);    //对右边进行排序  
        MergeSort(s,t,b,mid,e);//合并排序后的数列
    }  
}  
  
  
void main()
{  
	int temp[10];
    int a[10]={2,5,1,11,4,9,7,8,6,0};  
	printf("原数列为：");
    for(int i=0;i<10;i++)
	{  
        printf("%d ",a[i]);  
    }  
	printf("\n");
    MSort(a,temp,0,9);  
	printf("合并排序后为：");
    for(int j=0;j<10;j++)
	{  
        printf("%d ",a[j]);  
    }  
    printf("\n");  
} 
