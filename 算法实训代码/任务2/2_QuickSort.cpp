#include <stdio.h>
#include <stdlib.h>
void QuickSort(int a[],int left,int right) //����������
{	
	int i = left;//��������ָ��ָ��������±�
	int j = right;
	if(i>j)      //�ж�������ֵ��С���ݹ����
		return;
	int p = a[i];//��¼���ֵ
	while(i<j)//һ��ѭ�����Եõ�����˵���඼�ȱ��С����˵��Ҳ඼�ȱ�˴�
	{
		while(i<j && a[j] >= p)//���ұ߿�ʼ�ұȱ��С��Ϊֹ
			j--;
		a[i] = a[j];//����С������ֵ�����
		while(i<j && a[i] <= p)//����߿�ʼ�ұȱ�˴��Ϊֹ
			i++;
		a[j] = a[i];//���ϴ������ֵ���ұ�
	}
	a[i] = p;//�����ֵ����������
	//һ��ѭ�����
	QuickSort(a,left,i-1); //�������ݹ�
	QuickSort(a,i+1,right);//�����Ҳ�ݹ�
} 

void sort(int a[],size_t len)//���ÿ������� 
{
	QuickSort(a,0,len-1);
}


void main()
{
	int a[10]={9,5,7,6,1,3,4,8,11,2};

	printf("ԭ����Ϊ��\n");//���ԭ����
	for(int i=0;i<10;i++)
	{  
        printf("%d ",a[i]);  
    } 
	
	sort(a,10);//����������

	printf("\n���������Ϊ��\n");//�������������
		for(int j=0;j<10;j++)
	{  
        printf("%d ",a[j]);  
    }
	printf("\n");

}




















/*
void show(int a[],int len)//���
{
	for(int i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
}


//show(a,10);*/