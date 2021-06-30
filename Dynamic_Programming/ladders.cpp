#include<iostream>
using namespace std;

int ladder(int n,int k,int dp[])
{
	// Here we need to find the number of ways by which we can reach to n

	//base case

	if(n==0)
		return 1; //This is due to standing at ground is also a step


	//recursive case

	int ways=0;

	for(int i=1;i<=k;i++)  //means we have k options that is from 4 we can reach to 3 2 1 since k=3;
	{
		if(n-i>=0)
		{
			ways+=ladder(n-i,k,dp);
		}

	}

	return ways;

}




int main()
{
	// Here we first need to know the value of step we want to reach and number of steps that we can jump at a time

	int n;
	int k;

	cout<<"Enter the value of n and k"<<endl;
	cin>>n>>k;

	int dp[n+1]={0};

	int ways=ladder(n,k,dp);

	cout<<ways<<endl;


	return 0;
}