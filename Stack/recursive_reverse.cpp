#include<iostream>
#include <stack>

using namespace std;


void insert_at_bottom(stack <int> &s1 , int x)
{

	if(s1.empty())
	{
		s1.push(x);
		return;
	}

	int z=s1.top();
	s1.pop();

	insert_at_bottom(s1,x);
	s1.push(z);

}

void rec_reverse(stack<int> &s1)
{
	int x;
	if(!s1.empty())
	{
		x=s1.top();
		s1.pop();
		rec_reverse(s1);
		insert_at_bottom(s1,x);
	}

}




int main()
{

	stack <int> s;
	for(int i=1;i<=4;i++)
	{
		s.push(i);
	}

	rec_reverse(s);

	while(!s.empty())
	{
		int y=s.top();
		cout<<y<<"\n";
		s.pop();
	}
}