#include <iostream>
#include <climits>

using namespace std;

int rod(int rodl,int size,int length[],int price[],int dp[])
{
	//base case

	if(rodl==0 || size==0)
		return 0;

	//lookup

	if(dp[rodl]!=0)
	{
		return dp[rodl];
	}

	if(length[size-1]> rodl)
	{
		return rod(rodl,size-1,length,price,dp); 
	}

	else
	{
		//first will be when we have taken the rodl 
		int a=rod(rodl-length[size-1],size-1,length,price,dp)+price[size-1];
		//second case is when we have taken the rodl but we want to take it again
		int b=rod(rodl-length[size-1],size,length,price,dp)+price[size-1];
		// third case is when we dont take the rodl
		int c=rod(rodl,size-1,length,price,dp);

		//now we know the profit is the maximum that is returned from these three

		dp[rodl]=max(max(a,b),c);

		return dp[rodl];

	}


}

int main()
{
	//give me rod length

	int rodl;
	cin>>rodl;
	int length[]={1,2,3,4,5,6,7,8};
	int size=sizeof(length)/sizeof(length[0]);
	int price[]={3,5,8,9,10,17,17,20};


	int dp[100]={0};

	int profit=rod(rodl,size,length,price,dp);

	cout<<profit<<endl;
}