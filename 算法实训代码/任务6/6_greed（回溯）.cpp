#include<stdio.h>
#include<algorithm>
using namespace std;
/*����ṹ����Ʒ*/
struct node
{
    int v,w;//vΪ��ֵwΪ��Ʒ����
}a[101];
int cmp(node A,node B)
{
    return A.v>B.v;
}
int main()
{
    int i,j,sum,s,m,n;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
		printf("��������Ʒ�����ͱ���������");
        scanf("%d%d",&s,&m);//sΪ��Ʒ������m��Ϊ��������

        for(i=0; i<s; i++)
		{
			printf("�������%d����Ʒ�ļ�ֵ��������",i+1);
            scanf("%d%d",&a[i].v,&a[i].w);
		}
        sort(a,a+s,cmp);

        /*̰���㷨����*/
        for(i=0; i<s; i++)
        {
            if(m<a[i].w)
            {
                sum=sum+a[i].v*m;//�����ɲ�
                m=0;
                break;
            }
            else
            {
                sum=sum+a[i].v*a[i].w;
                m=m-a[i].w;
            }
        }
        printf("���Ž�Ϊ��%d\n",sum);
    }
    return 0;
}
