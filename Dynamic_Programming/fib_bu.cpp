#include <iostream>
using namespace std;

int main()
{

	int n;
	cin>>n;

	// create the array
	int fib[100]={0};

	//set the base condition values 
	
	if(n==0||n==1)
		return n;

	fib[0]=0;
	fib[1]=1;

	for(int i=2;i<=n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}


	cout<<fib[n]<<endl;;

	return 0;


}