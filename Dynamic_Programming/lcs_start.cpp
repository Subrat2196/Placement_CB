#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Here we need to find the longest common subsequence

int lcs(string s1,string s2,int i,int j,int dp[][100])
{
	//base case
	if(i==s1.length() || j==s2.length())
		return 0;

	// lookup

	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}

	// recursive case

	if(s1[i]==s2[j])
	{
		return 1+lcs(s1,s2,i+1,j+1,dp);
	}

	else
	{
		int a=lcs(s1,s2,i+1,j,dp);
		int b=lcs(s1,s2,i,j+1,dp);

		int ans=max(a,b);

		return dp[i][j]=ans;
	}
}


int main()
{

	string s1="ABE";
	string s2="ABCE";

	int dp[100][100]={0};

	int count=lcs(s1,s2,0,0,dp);

	cout<<lcs(s1,s2,0,0,dp)<<endl;

	return 0;


}