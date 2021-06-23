#include <iostream>
#include <algorithm>

using namespace std;

int ans=-1;

void solve(int a[],int n,int key)
{

	int i=0;

	while(i<n)
	{
		if(a[i]==key)
		{
			ans=i;
			return;
		}

		int element=abs(a[i]-key);
		int step=max(1,element/key);

		i=i+step;
	}

	return;

}



int main()
{
	ans=-1;

	int a[]={12,11,9,7,6,5};

	int n=sizeof(a)/sizeof(a[0]);

	int key=7;
	solve(a,n,key);

	cout<<ans;


}