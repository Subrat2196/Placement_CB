#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


int main()
{

	int arr[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(arr)/sizeof(int);

	int money=168;

	//Here you need to make the change using minimum number of coins

	//Here we need to find the coin that has the highest value which is less than 168 and subtract it then again do it

	//here we know the higher bound gives the value strictly > key

	//we want smaller than key, therefore we can use our own comparator

	while(money>0)
	{
		auto ub=upper_bound(arr,arr+n,money)-arr-1;
		int m=arr[ub];
		cout<<m<<",";
		money=money-m;
	}
	return 0;
}