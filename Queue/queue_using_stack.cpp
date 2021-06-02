#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue
	{
		stack <T> s1;
		stack <T> s2;
	public:		

	void push(T x)
	{	
		s1.push(x);
	}

	void pop()
	{
		//remove the last added element from q1, for this we need two things
		// 1-> push n-1 elements to q2 and pop the last element of q1
		// 2-> interchange the name of q1 and q2
		if(s1.empty())
			return;

		while(s1.size()>1)
		{
			T element=s1.top();
			s2.push(element);
			s1.pop();			
		}
		//removes the last element
		s1.pop();

		while(!s2.empty())
		{
			T element=s2.top();
			s1.push(element);
			s2.pop();
		}


	}

	T front()
	{
		while(s1.size()>0)
		{
			T element=s1.top();
			s2.push(element);
			s1.pop();
				
		}


		T element=s2.top();
		
		while(!s2.empty())
		{
			T element=s2.top();
			s1.push(element);
			s2.pop();
		}
		return element;

	}

	int size()
	{
		return s1.size()+s2.size();
	}

	bool isEmpty()
	{
		return size()==0;
	}

};
int main()
{

	Queue<int> q;

	for(int i=1;i<=10;i++)
	{
		q.push(i);
	}


	q.pop();
	q.pop();

	while(!q.isEmpty())
	{
		cout<<q.front()<<" ";
		q.pop();

	}



	return 0;

}