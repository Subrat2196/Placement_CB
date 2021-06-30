#include <iostream>
#include <climits>
using namespace std;

//Here we are using the bottom up approach so it will be a recursive program

int main()
{
	int n;
	cout<<"Enter the number"<<endl;

	cin>>n;

	//create a dp table

	int dp[100]={0};

	//set the base case in the dp table

	dp[1]=0;

	// We are looping from 2 to n
	
	//at each step we see that which step we can go from here

	for(int i=2;i<=n;i++)
	{
		int a=dp[i-1];
		int b=INT_MAX;
		int c=INT_MAX;

		if((i%2)==0)
		{
			b=dp[(i/2)];
		}

		if((i%3)==0)
		{
			c=dp[(i/3)];
		}

		
		dp[i]=min(min(a,b),c)+1;
		//Take three value a,b,c starting at max
	}

	cout<<dp[n]<<endl;

	return 0;

}