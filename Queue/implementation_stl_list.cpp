#include <iostream>
#include <forward_list>
#include <list>
using namespace std;

class Queue
 {

 	int cs;
 	list<int> ll;
 public:
 	Queue()
 	{
 		cs=0;
 	}

 	void push(int data)
 	{
 		ll.push_back(data);
 		cs=cs+1;
 	}

 	bool isEmpty()
 	{
 		return cs==0;
 	}
 	void pop()
 	{
 		if(!isEmpty())
 		{
 			cs--;
 			ll.pop_front();
 		}	

 	}


 	int front()
 	{
 		return ll.front();

 	}

 	
 }; 



 	int main()
 	{

 		Queue q;
 		for(int i=1;i<=10;i++)
 			q.push(i);

 		while(!q.isEmpty())
 		{
 			cout<<q.front()<<"-";
 			q.pop();
 		}

 	}