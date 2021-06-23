#include <iostream>
#include <algorithm>

using namespace std;

int maxi;
int mini;

void solve(int a[],int n)
{
	
	int i=0;
	
	if(n%2==0)
	{
		if(a[i]>a[i+1])
		{
			maxi=max(a[i],a[i+1]);
			mini=min(a[i+1],a[i]);
		}

		i=2;
	}

	else
	{
		maxi=a[0];
		mini=a[0];
		i=1;
	}


	while(i<n-1)
	{
		if(a[i]>a[i+1])
		{
			if(a[i]>maxi)
				maxi=a[i];

			if(a[i+1]<mini)
				mini=a[i+1];
		}
		else
		{
			if(a[i+1]>maxi)
				maxi=a[i+1];

			if(a[i]<mini)
				mini=a[i];

		}

		i=i+2;
	}


}


int main()
{

	int a[]={4,3,9,7,6,8,10,12,2,5};

	int n=sizeof(a)/sizeof(a[0]);

	if(n==1)
	{
		maxi=a[0];
		mini=a[0];
		cout<<maxi<<"  "<<mini;
		return 0;
	}


	solve(a,n);

	cout<<"Maximum element is "<<maxi<<" and the minimum element is "<<mini<<endl;

}