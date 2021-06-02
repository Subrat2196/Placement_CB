#include <iostream>
#include <climits>
using namespace std;

void max_min(int a[],int n)
{
	int max=INT_MIN;
	int min=INT_MAX;

	for(int i=0;i<n;i++)
		{
			if(a[i]>max)
				max=a[i];
			else
			{
				if(a[i]<min)
					min=a[i];
			}
			
		}

		cout<<"Max Element in the array is "<<max<<"\n";
		cout<<"Min Element in the array is "<<min<<"\n";

}

void pair_min_max(int a[],int n)
{
	int max,min,i;

	if(n==0)
	{
		return;
	}
	if(n==1)
	{
		cout<<"Max = "<<a[0]<<"\0";
		cout<<"Min = "<<a[0]<<"\0";
	}

	if(n%2==0)
	{
		if(a[0]>a[1])
		{
			max=a[0];
			min=a[1];
		}
		else
		{
			max=a[1];
			min=a[0];
		}
		i=2;
	}
	else
	{
		max=a[0];
		min=a[0];
		i=1;
	}

	while(i<n-1)
	{
		if(a[i]>a[i+1])
		{
			if(a[i]>max)
			{
				max=a[i];
			}
			if(a[i+1]<min)
			{
				min=a[i+1];
			}
		}
		else
		{ 
			if(a[i+1]>max)
			{
				max=a[i+1];
			}
			if(a[i]<min)
			{
				min=a[i];
			}
	
		}
		i=i+2;

	}

	cout<<"Max = "<<max<<"\0";
	cout<<"Min = "<<min<<"\0";






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

	pair_min_max(a,n);


return 0;
}