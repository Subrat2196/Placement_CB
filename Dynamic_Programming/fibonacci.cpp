#include <iostream>
using namespace std;

int fibonacci(int n)
{
	//base conditions

	if(n==1||n==0)
		return n;

	// now the recursive conditions

	else
	{
		int a=fibonacci(n-1);
		int b=fibonacci(n-2);
		int sum=a+b;

		return sum;

	}




}


int main()
{
	int n;
	cin>>n;

	int sum=fibonacci(n);

	cout<<"The fibonacci of "<<n<<" is given by "<<sum<<endl;

	return 0;
		
}