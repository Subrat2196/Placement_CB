#include <iostream>
#include <climits>

using namespace std;

int KS01(int m,int n,int profit[],int wt[])
{
	//base case

	if(m==0||n==0)
		return 0;


	if(wt[n-1]>m)
		return KS01(m,n-1,profit,wt);

	else
	{
		int a=KS01(m-wt[n-1],n-1,profit,wt) + profit[n-1];
		int b=KS01(m,n-1,profit,wt);

		int c=max(a,b);

		return c;
	}
}

int main()
{
	//we need the capacity of the knapsack
	cout<<"Tell the capacity"<<endl;
	int m;
	cin>>m;

	int n=5;

	int profit[5]={25,70,50,10,60};
	int wt[5]={5,3,2,4,5};


	int maxProfit=KS01(m,n,profit,wt);

	cout<<maxProfit<<endl;

	return 0;

}