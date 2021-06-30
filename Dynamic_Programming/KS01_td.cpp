#include <iostream>
#include <climits>
using namespace std;

int KS01(int m,int n,int profit[],int wt[],int dp[][100])
{
	//base case
	if(m==0||n==0)
		return 0;

	// lookup

	if(dp[m][n-1]!=0)
	{
		return dp[m][n-1];
	}

	//recursive case

	if(wt[n-1]>m)
		return KS01(m,n-1,profit,wt,dp);

	else
	{
		//first case is when we added that weight and profit

		int a= KS01(m-wt[n-1],n-1,profit,wt,dp) + profit[n-1];
		int b= KS01(m,n-1,profit,wt,dp);

		int c=max(a,b);
		dp[m][n-1]=c;

		return c;
	}

}



int main()
{
	cout<<"Tell the capacity"<<endl;
	int m;
	cin>>m;

	int n=5;

	int profit[5]={25,70,50,10,60};
	int wt[5]={5,3,2,4,5};

	int dp[100][100]={0};

	int maxProfit=KS01(m,n,profit,wt,dp);

	cout<<maxProfit<<endl;	


}