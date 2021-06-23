#include <iostream>
#include <algorithm>

using namespace std;

bool flag=false;
int position;	
int ans_first=-1;
int ans_last=-1;

void first(int a[],int start,int end ,int key)
{

	while(start<=end)
	{
		int mid=(start+end)/2;
		if(key==a[mid])
		{
			ans_first=mid;
			end=mid-1;
		}

		else if(key>a[mid])
			start=mid+1;

		else
			end=mid-1;

	}
}

void last(int a[],int start,int end ,int key)
{

	while(start<=end)
	{
		int mid=(start+end)/2;
		if(key==a[mid])
		{
			ans_last=mid;
			start=mid+1;
		}

		else if(key>a[mid])
			start=mid+1;

		else
			end=mid-1;

	}
}

int main()
{

int arr[]={3,4,5,5,5,5,6,7,8};
int n=sizeof(arr)/sizeof(int);

int key;
cout<<"Type the key to be found"<<endl;
cin>>key;

first(arr,0,n-1,key);
last(arr,0,n-1,key);

cout<<ans_first<<" ";
cout<<ans_last<<" ";


return 0;

}