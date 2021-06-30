#include <iostream>
#include <climits>

using namespace std;

int mini_coins(int n,int dom[],int size,int dp[])
{
	//base case

	if(n==0)
		return 0;

	//lookup

	if(dp[n]!=0)
		return dp[n];

	//recursive case

	int ans=INT_MAX;
	for(int i=0;i<size;i++)
	{
		//only when n=dom[i] >=0 we will go to a step

		if(n-dom[i]>=0)
		{
			int sub_prob=mini_coins(n-dom[i],dom,size,dp);
			ans=min(ans,sub_prob+1);
		}
	}

	dp[n]=ans;

	return dp[n];
}


int main()
{
	//Tell me the amount

	int n;
	cin>>n;

	//Tell me the available dominations

	int dom[]={1,2,5,10,15};

	int size=sizeof(dom)/sizeof(dom[0]);

	int dp[100]={0};

	int ans=mini_coins(n,dom,size,dp);

	cout<<ans<<endl;

	return 0;


}