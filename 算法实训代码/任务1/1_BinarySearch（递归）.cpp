#include<stdio.h>
#include<iostream>
using namespace std;
int a[100] = {1,3,5,7,9,10,11,13,15,19};//�����е�������С����
int k;//Ҫ�ҵ�����
int BinarySearch(int right,int left)//���ֲ��Һ���
{
    int mid = (right+left)/2;//����һ���м�ֵ�����ڰ�������ȷ�Ϊ��������
    if(right>left)//�������û���ҵ��𰸣�����-1
        return -1;
    else
    {
        if(a[mid] == k)
            return mid;//�ҵ�������λ��.
        else if(a[mid]>k) //������С���м�ֵ
            return BinarySearch(right,mid-1);//�����
         else
            return BinarySearch(mid+1,left);//���ұ�
    }
}
int main()
{
	printf("��������ҵ�����");//����Ҫ���ҵ���
	scanf("%d",&k);
	printf("����������λ��Ϊ��");
	cout<<BinarySearch(0,9)+1;//������a[0]��a[9]
	printf("\n");
	return 0;
}






        //cin>>k;//����Ҫ�ҵ�����c���԰�cin��Ϊscanf����