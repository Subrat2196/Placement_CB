#include <iostream>
#include <climits>

using namespace std;

int Rod(int rodl,int length[],int size,int price[])
{
	
	//base case

	if(rodl==0)
		return 0;
	if(size==0)
		return 0;

	//recursive cases

	if(length[size-1]>rodl)
		return Rod(rodl,length,size-1,price);


	else
	{
		int a=Rod(rodl-length[size-1],length,size-1,price)+price[size-1];
		int b=Rod(rodl-length[size-1],length,size,price)+price[size-1];
		int c=Rod(rodl,length,size-1,price);

		int ans=max(max(a,b),c);

		return ans;

	}
}



int main()
{
	//give the length of rod
	int rodl;
	cin>>rodl;

	//give the length array

	int length[]={1,2,3,4,5,6,7,8};
	int size=sizeof(length)/sizeof(length[0]);
	int price[]={3,5,8,9,10,17,17,20};
	

	int profit=Rod(rodl,length,size,price);

	cout<<profit<<endl;

	return 0;
}