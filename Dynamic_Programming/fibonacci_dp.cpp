#include <iostream>
using namespace std;

int fibonacci(int n,int dp[])
{
	//base case 
	if(n==0||n==1)
		return n;

	//Lookup in this case also

	if(dp[n]!=0)
		return dp[n];

	// Recursive case
	int a;

	if(dp[n-1]!=0)
		a=dp[n-1];
	else
	{		
		dp[n-1]=fibonacci(n-1,dp);
		a=dp[n-1];	
	}

	int b;
	if(dp[n-2]!=0)
		b=dp[n-2];
	else
	{		
		dp[n-2]=fibonacci(n-2,dp);
		b=dp[n-2];	
	}

	dp[n]=a+b;
	return dp[n];
}



int main()
{	
	//Take the value of n since you want to calculate fib(n)

	int dp[100]={0};

	int n;
	cin>>n;

	int ans=fibonacci(n,dp);

	cout<<ans<<endl;
	return 0;
}