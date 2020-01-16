#include<iostream>
using namespace std;
 
const int W = 150;
const int number = 5;
const int VALUE[] = {60, 20, 10, 60, 100};
const int WEIGHT[] = {20, 30, 50, 60, 80};
 
 
//function Make( i {处理到第i件物品} , j{剩余的空间为j}) :integer;
int Make(int i, int j)
{  
	int r1 = 0;
	int r2 = 0;
	int r = 0;
	
	if (i == -1)
	{
		return 0;
	}
 
	if(j >= WEIGHT[i])   //背包剩余空间可以放下物品 i  
	{
		r1 = Make(i-1,j - WEIGHT[i]) + VALUE[i]; //第i件物品放入所能得到的价值
		r2 = Make(i-1,j); //第i件物品不放所能得到的价值  
		r = (r1>r2)?r1:r2;
	}   
 
	return r;
}
 
 
void main()
{
	int maxValue = Make(number-1, W);
	cout<<"maxValue: "<<maxValue<<endl;
}

