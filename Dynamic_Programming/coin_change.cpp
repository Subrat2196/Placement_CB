#include <iostream>
#include <climits>

using namespace std;

int mini_coins(int n,int coins[],int size)
{
	//base condition 

	if(n==0)
		return 0;

	//here we will write the recursive case
	int ans=INT_MAX;

	for(int i=0;i<size;i++)
	{
		if(n-coins[i]>=0)
		{
			int sub_prob=mini_coins(n-coins[i],coins,size);
			ans=min(ans,sub_prob+1);
		}
	}

	return ans;



}



int main()
{
	//Here we need to input the amount we want
	int n;
	cin>>n;

	//we need to calculate the minimum coins

	int coins[]={1,7,10};

	int size=sizeof(coins)/sizeof(coins[0]);

	int ans=mini_coins(n,coins,size);

	cout<<"Minimum coins are "<<ans;

}