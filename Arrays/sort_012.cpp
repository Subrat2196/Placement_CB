#include <iostream>
using namespace std;

void sort_012(int a[],int n)
{
	int low=0,mid=0,high=n-1;

	while(mid<=high)
	{
		switch(a[mid])
		{
			case 0: 
				swap(a[low],a[mid]);
				mid++;low++;
				break; 

			case 1: 
				mid++;
				break;

			case 2:
				swap(a[mid],a[high]);
				high--;
				break;
		}


	}

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

	sort_012(a,n);
	
	cout<<"\n";	

		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<",";
		}


	return 0;

}