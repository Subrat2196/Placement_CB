#include <iostream>
using namespace std;

void negative_to_begin(int a[],int n)
{
	int low=0;
	int mid=0;


	while(mid<=n)
	{
		if(a[mid]>=0)
		{
			mid++;
		}
		else
		{
			swap(a[mid],a[low]);
			mid++;low++;
		}
	}

return;

}

int main()
{

	int n;
	cout<<"Enter the number of elements you want in your array"<<"\n";
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<",";
	}

	negative_to_begin(a,n);
	
	cout<<"\n";	

		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<",";
		}


	return 0;

}