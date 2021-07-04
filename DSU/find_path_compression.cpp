#include<iostream>
#include <list>

using namespace std;

//here we will first create an edge list and see the number of vertices  
class Graph
{
	int V;
	//edge list has edges from x to y as pairs
	list<pair<int,int>> l;

public:

	Graph(int V)
	{
		this->V=V;
	}

	//Here it is a directed graph 
	void add_edge(int x,int y)
	{
		l.push_back(make_pair(x,y));
	}

	int find_set_compression(int i,int parent[])
	{
		if(parent[i]==-1)
			return i;
		else
			return parent[i]=find_set_compression(parent[i],parent);
	}

	void union_set(int a,int b,int parent[])
	{

		// We need to union the two sets which are a and b
		int s1=find_set_compression(a,parent); //we find the set of a
		int s2=find_set_compression(b,parent); // we find the set of b

		if(s1!=s2)
		{
			parent[s2]=s1;
		}
	}



	bool contains_cycle()
	{
		//step1 - We will create a parent array that will store the parents of sets
		int *parent=new int[V];
	
		//initally we will keep each one of them as a seperate set
		for(int i=0;i<V;i++)
		{
			parent[i]=-1;
		}

		//step2 - here we are traversing the edge list

		for(auto x:l)
		{
			// x will be a pair
			int a=x.first;
			int b=x.second;

			//here we need to see that a and b doesnt belong to the same set

			int s1=find_set_compression(a,parent);
			int s2=find_set_compression(b,parent);

			if(s1!=s2)
			{
				union_set(s1,s2,parent);
			}
			else
			{
				return true;
			}

		}

		delete [] parent;

		return false;
	}
};


int main()
{

	Graph g(4);

	g.add_edge(0,1);
	g.add_edge(1,3);
	g.add_edge(3,2);
	 // g.add_edge(3,1);

	if(g.contains_cycle())
	{
		cout<<"cycle"<<endl;
	}

	else
	{
		cout<<"no cycle"<<endl;
	}
	


	return 0;
}