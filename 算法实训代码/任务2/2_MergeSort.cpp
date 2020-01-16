#include<iostream>  
#include<cstdio>  
  
void MergeSort(int s[],int t[],int b,int mid,int e){//��s[b...mid]��s[mid+1...e]�ϲ�����
    int i=b;//i->ǰһ����(�����е�����ֵ)  
    int j=mid+1;//j->��һ����(�����е�����ֵ)
    int k=0;//k->t����  
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
    for(i=0;i<k;i++){  //ÿ�ζ���������t��ֵ���ظ�s������s��������[b,e]Ҳ�������
        s[b+i]=t[i];  
    }  
}  
  
  
void MSort(int s[],int t[],int b,int e)//������
{  
    if(b<e)
	{  
        int mid;  
        mid=(b+e)/2;  //����һ���м�ֵ,�Ա��ڷ�Ϊ����������
        MSort(s,t,b,mid);      //����߽�������
        MSort(s,t,mid+1,e);    //���ұ߽�������  
        MergeSort(s,t,b,mid,e);//�ϲ�����������
    }  
}  
  
  
void main()
{  
	int temp[10];
    int a[10]={2,5,1,11,4,9,7,8,6,0};  
	printf("ԭ����Ϊ��");
    for(int i=0;i<10;i++)
	{  
        printf("%d ",a[i]);  
    }  
	printf("\n");
    MSort(a,temp,0,9);  
	printf("�ϲ������Ϊ��");
    for(int j=0;j<10;j++)
	{  
        printf("%d ",a[j]);  
    }  
    printf("\n");  
} 
