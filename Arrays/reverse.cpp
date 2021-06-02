#include<iostream>
using namespace std;


void reverse(int arr[],int n)
{
	int start=0;
	int end=n-1;

	while(start<end)
	{
		swap(arr[start],arr[end]);
		start=start+1;
		end=end-1;
	}

	cout<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<",";
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

	reverse(a,n);

	

}