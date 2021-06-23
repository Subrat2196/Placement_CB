#include <iostream>
#include <algorithm>

using namespace std;

bool flag=false;
int position;

void binary_search(int a[],int start,int end ,int key)
{
	
	if(start>end)
		return;

	int mid=(start+end)/2;

	if(key==a[mid])
	{
		position=mid;
		flag=true;
		return;
	}

	else if(key>a[mid])
		return binary_search(a,mid+1,end,key);

	else
		return binary_search(a,0,mid-1,key);

}

int main()
{

int arr[]={3,4,5,6,7,8};
int n=sizeof(arr)/sizeof(int);

int key;
cout<<"Type the key to be found"<<endl;
cin>>key;

binary_search(arr,0,n-1,key);

if(flag)
	cout<<"element found at position"<<position<<endl;

else
	cout<<"element not found"<<endl;

}