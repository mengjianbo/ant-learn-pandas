#include<stdio.h>
int main()
{
	int x,left=0,right=5,f=0;
	int mid;
	int a[10] = {1,3,5,7,9,10,11,13,15,19};//����һ������
	printf("��������ҵ�����");
	scanf("%d",&x);//����������ҵ���
	while(f==0 && left<=right)//�ж��������Ҵ�С
	{
		mid=(left+right)/2;//ȡ�����м�ֵ
		if (x==a[mid])   //��������������м�ֵ
			f=1;
		else if(x<a[mid])//������������м�ֵС
			right=mid-1;
		else             //������������м�ֵ��
			left=mid+1;
	}
	if(f==0)
		printf("û���ҵ�/n");
	else
		printf("����������λ��Ϊ��%d\n",mid+1);
}

