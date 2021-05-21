#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<pair<int,int>> l1; //creates one list of pair of integers
	list<pair<int,int>> l2[20];  //It is an array list that is we are creating an array og 20 lists 
	//and l1 is the pointer to that array

	//we can also do it dynamically by asking number of lists we want to create,
	//it can be same as the no of vertices
 
	list<pair<int,int>> *l;
	int n;
	cin>>n;

	l=new list<pair<int,int>>[n]; 

	//now we will add the vertices edges and weights to the graph
	//lets first ask the user how many number of edges does the user wants 

	int e;
	cin>>e;

	int x,y,wt;
	//let us say that we have an edge x to y with the weight w
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>wt;

		l[x].push_back(make_pair(y,wt));
		l[y].push_back(make_pair(x,wt));
	}

	//Print every linked list
	for(int i=0;i<n;i++)
	{
		cout<<"Linked List "<<i<<"->";
		for(auto xp:l[i])
		{
			cout<<"("<<xp.first<<","<<xp.second<<"),";
		}

	}

	return 0;
}