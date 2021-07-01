#include<iostream>
using namespace std;


int main()
{

	//tell me the steps
	//tell me the max_jump

	int n,k;
	cin>>n>>k;

	int dp[100]={0};

	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=k;i++)
	{
		dp[i]=2*dp[i-1];
	}

	for(int i=k+1;i<=n;i++)
	{
		dp[i]=2*dp[i-1]- dp[i-k-1]; 
	}


	for(int i=0;i<=n;i++)
	{
		cout<<dp[i]<<"  ";
	}

	cout<<endl;

	cout<<dp[n]<<endl;


	return 0;

}