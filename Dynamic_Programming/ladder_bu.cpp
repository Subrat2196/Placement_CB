#include <iostream>
using namespace std;

int ladder(int n,int k,int dp[])
{
	// set the base case

	dp[0]=1;

	//comcept is to go to 1 and sum all before it which are at a distance 3 or less

	for(int i=1;i<=n;i++)
	{
		int csum=0;
		int j=i-1;
		while(j>=0 and j>=i-3)
		{
			csum+=dp[j];
			j--;
		}

		dp[i]=csum;
	}

	return dp[n];
}

int ladder_cb(int n,int k,int dp[])
{
	// set the base case

	dp[0]=1;

	//comcept is to go to 1 and sum all before it which are at a distance 3 or less

	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
				dp[i]+=dp[i-j];
		}
	}

	return dp[n];
}





int main()
{	
	//tell me the value of step to reach and the max jump

	int n,k;
	cin>>n>>k;

	int dp[100]={0};

	int ways=ladder_cb(n,k,dp);

	cout<<ways<<endl;

return 0;

}