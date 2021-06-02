#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
	{
		queue <T> q1;
		queue <T> q2;
	public:		

	void push(T x)
	{	
		q1.push(x);
	}

	void pop()
	{
		//remove the last added element from q1, for this we need two things
		// 1-> push n-1 elements to q2 and pop the last element of q1
		// 2-> interchange the name of q1 and q2
		if(q1.empty())
			return;

		while(q1.size()>1)
		{
			T element=q1.front();
			q2.push(element);
			q1.pop();			
		}
		//removes the last element
		q1.pop();

		//swap the names of q1 and q2

		swap(q1,q2);


	}

	T top()
	{
		while(q1.size()>1)
		{
			T element=q1.front();
			q2.push(element);
			q1.pop();
				
		}

		T element=q1.front();
		q1.pop();
		q2.push(element);

		swap(q1,q2);

		return element;

	}

	int size()
	{
		return q1.size()+q2.size();
	}

	bool isEmpty()
	{
		return size()==0;
	}

};
int main()
{

	Stack<int> s;

	for(int i=1;i<=10;i++)
	{
		s.push(i);
	}


	s.pop();
	s.pop();

	while(!s.isEmpty())
	{
		cout<<s.top()<<" ";
		s.pop();

	}



	return 0;

}
