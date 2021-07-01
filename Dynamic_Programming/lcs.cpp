#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Here we need to find the longest common subsequence

int lcs(string s1,string s2,int m,int n,int dp[][100])
{
	//base case
	if(m==0||n==0)
		return 0;

	// recursive case

	if(dp[m-1][n-1]!=0)
		return dp[m-1][n-1];

	if(s1[m-1]==s2[n-1])
	{
		return dp[m-1][n-1]=1+lcs(s1,s2,m-1,n-1,dp);
	}

	else
	{
		int a=lcs(s1,s2,m-1,n,dp);
		int b=lcs(s1,s2,m,n-1,dp);

		int ans=max(a,b);

		return dp[m-1][n-1]=ans;
	}
}


int main()
{

	string s1="ABC";
	string s2="AB";

	int dp[100][100]={0};
	int m=s1.length();
	int n=s2.length();


	int count=lcs(s1,s2,m,n,dp);

	cout<<lcs(s1,s2,m,n,dp)<<endl;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}

		cout<<endl;
	}

	return 0;


}