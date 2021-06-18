#include<iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	priority_queue<int,vector<int>,greater<int>> pq;   //here greater<int> is a predefined comparator function for the stl library
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		pq.push(no);
	}

	cout<<endl;

	//Remove the elements from the heap

	while(!pq.empty())
	{
		int item=pq.top();
		pq.pop();
		cout<<item<<" ";
	}


return 0;

}	