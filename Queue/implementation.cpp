#include<iostream>

using namespace std;

class Queue
{
	int *arr;
	int f,r,cs,ms; //f is front,r is rear, cs is current size and ms is max size

public:

	Queue(int ds=5)     //default size
	{
		arr=new int[ds];
		cs=0;
		ms=ds;
		f=0;
		r=ms-1;
	}

	bool full()
	{
		return cs==ms;
	}	
	void push(int data)
	{
		if(full())
		{
			return;
		}

		r=(r+1)%ms;
		arr[r]=data;
		cs++;

	}

	bool empty()
	{
		return cs==0;
	}

	void pop()
	{
		if(empty())
		{
			return;
		}

		f=(f+1)%ms;
		cs--; 
	}

	int front()
	{
		if(cs==0)
		{
			return -1;
		}

		return arr[f];
	}
	
	~Queue()    //There are two things here, 1-pointer arr 2-heap memory pointed by arr
	{
		if(arr!=NULL)
		{
			delete[] arr;   //It will delete the heap memory
			arr=NULL;       //It will make the array pointer as NULL
		}
	}
};



int main()
{

	Queue q;
	for(int i=0;i<=6;i++)     //Here since the size of array is only 5,therefore 5 and 6 wont get inserted
	{
		q.push(i);
	}

	q.pop();
	q.pop();

	q.push(7);

	while(!q.empty())
	{
		cout<<q.front()<<",";
		q.pop();
	}

return 0;
}