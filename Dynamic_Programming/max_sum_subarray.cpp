#include <iostream>
#include <climits>

using namespace std;

int mss(int a[],int n)
{
	int dp[n]={0};

  //here we set that if array's first element is positive set the dp[0] as a[0] otherwise set as 0

	dp[0]=a[0]>0?a[0]:0;

	//here the dp array gives the sum upto ith index  

	int msum=dp[0];

	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+a[i];

		if(dp[i]<0)
			dp[i]=0;

		msum=max(msum,dp[i]);
	}
	return msum;
}


int main()
{

	int a[]={-3,2,5,-1,6,3,-2,7,-5,2};

	int size=sizeof(a)/sizeof(a[0]);

	int maximum=mss(a,size);

	cout<<maximum<<endl;

	return 0;
}