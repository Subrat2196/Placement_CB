#include <iostream>
#include <climits>

using namespace std;

int main()
{
	//Input the number
	
	int n;
	cin>>n;

	//tell me the dominations

	int dom[]={1,7,10};

	int size=sizeof(dom)/sizeof(dom[0]);

	int dp[100]={0};

	//Set the base case in dp array
	dp[0]=0;

	//intitaling ans to max
	

	//looping upto n
	for(int i=1;i<=n;i++)
	{
		int ans=INT_MAX;
		for(int j=0;j<size;j++)
		{
			if(i-dom[j]>=0)
			{	
				int val=dp[i-dom[j]] +1;
				ans=min(ans,val);
			}

		}

		dp[i]=ans;

	}

	cout<<dp[n];

	return 0;
}
