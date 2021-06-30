#include <iostream>
#include <climits>
using namespace std;

int solve(int i,int j,int prices[],int dp[][100],int year)
{
	//base case

	if(i>j)
		return 0;

	//lookup

	if(dp[i][j]!=0)
		return dp[i][j];

	//recursive case

	int first=prices[i]*year + solve(i+1,j,prices,dp,year+1);
	int second=prices[j]*year + solve(i,j-1,prices,dp,year+1);

	int ans=max(first,second);

	dp[i][j]=ans;

	return dp[i][j];


}


int main()
{
	// Tell me the wines and their prices

	int prices[]={2,3,5,1,4};

	//we calculate the size since it might come handy in future

	int size=sizeof(prices)/sizeof(prices[0]);

	int dp[100][100]={0};

	int i=0;
	int j=size-1;

	int year=1;

	int profit=solve(i,j,prices,dp,year);

	cout<<profit<<endl;
	return 0;

}