#include <iostream>
#include <climits>
using namespace std;

int solve(int n,int dp[])
{
	//base case

	if(n==1)
		return 0;

	//dp lookup

	if(dp[n]!=0)
		return dp[n];

	//recursive case

	int a=solve(n-1,dp);
	int b=INT_MAX;
	int c=INT_MAX;

	//we are doing this since every time we know 1 will get decremented but each time it won't be divisible by 2 or 3

	if(n%2==0)
	{
		b=solve(n/2,dp);
	}

	if(n%3==0)
	{
		b=solve(n/3,dp);
	}
	
	int ans=min(min(a,b),c)+1;
	dp[n]=ans;
	
	return dp[n];

}


int main()
{
	//enter the value of n

	cout<<"Enter the number "<<endl;


	int n;
	cin>>n;

	//make the dp array

	int dp[100]={0};

	int steps=solve(n,dp);

	cout<<steps<<endl;

	return 0;

}

