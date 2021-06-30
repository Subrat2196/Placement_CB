#include <iostream>
using namespace std;

int main()
{

	int n;
	cin>>n;

	//here we need to store the last 2 values and keep on changing 

	//set the base condition values 
	
	if(n==0||n==1)
		return n;

	int a=0;
	int b=1;

	int c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}

	cout<<c<<endl;

	return 0;


}