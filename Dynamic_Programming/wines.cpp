#include <iostream>
#include <climits>

using namespace std;

int profit(int i,int j,int price[],int year)
{
	//base case 

	if(i>j)
		return 0;

	//recursive case

	//We have 2 cases here, the first one is the 

	int first=price[i]*year + profit(i+1,j,price,year+1);
	int second=price[j]*year + profit(i,j-1,price,year+1);

	int ans=max(first,second);

	return ans;

}


int main()
{
	//Tell me the wines and their cost
	int price[]={2,3,5,1,4};
	int size=sizeof(price)/sizeof(price[0]);

	int year=1;//years will go till 5 since there are 5 bottles\

	int i=0;
	int j=size-1;

	int ans=profit(i,j,price,year);

	cout<<ans<<endl;

	return 0;
}