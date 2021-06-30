#include <iostream>
#include<climits>
using namespace std;

int min_steps(int n)
{
	// we need to give the base case

	if(n==1)
		return 0;

	// otherwise we need to take the minimum of three cases

	//here we will first see if it is actually divisible by it or not
	int a=min_steps(n-1)+1;

	int b=INT_MAX;
	int c=INT_MAX;

	if(n%2==0)
	{
		b=min_steps(n/2)+1; 
	}

	if(n%3==0)
	{
		c=min_steps(n/3)+1;
	}

	int ans=min(min(a,b),c); //here we need to take 1 step to go to a particular place 

	return ans;
}

int main()
{

	int n;
	cout<<"Enter the number you want the steps for"<<endl;
	cin>>n;

	cout<<min_steps(n)<<endl;

	return 0;


}

//here the problem is that we need to calcluate the minimum steps that we will have to reach from a particular number to 1

//operations that are allowed are n/2,n/3 if they are completely divisible and n-1;

