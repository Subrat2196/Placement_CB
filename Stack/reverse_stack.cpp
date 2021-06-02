#include<iostream>
#include <stack>

using namespace std;

void reverse_stack(stack<int> &s1)
{

	stack <int> s2;

	for(int i=0;i<s1.size();i++)
	{

		int n=s1.size()-i;

		int x=s1.top();
		s1.pop();

		while(n>1)
		{
			int y=s1.top();
			s1.pop();
			s2.push(y);

			n=n-1;
		}

		s1.push(x);

		while(!s2.empty())
		{
			int y=s2.top();
			s2.pop();
			s1.push(y);
		}
	}

 }


int main()
{

	stack <int> s;
	for(int i=1;i<=4;i++)
	{
		s.push(i);
	}

	reverse_stack(s);

	while(!s.empty())
	{
		int y=s.top();
		cout<<y<<"\n";
		s.pop();
	}
}