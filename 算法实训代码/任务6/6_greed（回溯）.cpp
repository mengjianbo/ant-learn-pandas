#include<stdio.h>
#include<algorithm>
using namespace std;
/*定义结构体物品*/
struct node
{
    int v,w;//v为价值w为物品重量
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
		printf("请输入物品个数和背包容量：");
        scanf("%d%d",&s,&m);//s为物品个数，m，为背包容量

        for(i=0; i<s; i++)
		{
			printf("请输入第%d个物品的价值和重量：",i+1);
            scanf("%d%d",&a[i].v,&a[i].w);
		}
        sort(a,a+s,cmp);

        /*贪心算法核心*/
        for(i=0; i<s; i++)
        {
            if(m<a[i].w)
            {
                sum=sum+a[i].v*m;//背包可拆
                m=0;
                break;
            }
            else
            {
                sum=sum+a[i].v*a[i].w;
                m=m-a[i].w;
            }
        }
        printf("最优解为：%d\n",sum);
    }
    return 0;
}
