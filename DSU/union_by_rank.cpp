#include <iostream>
#include <list>

using namespace std;

// We have three ways -> 1 -> Adjacency list   2-> 2D Array   3-> Edge list

// We are doing edge list here

class Graph
{
	int V;

	list<pair<int,int>> l;

public:

	Graph(int V)
	{
		this->V=V;
	}

	void add_edge(int x,int y)
	{
		l.push_back(make_pair(x,y));
	}

	// We will be applying here path compression
	// we will define the parent dynamically

	int find_set(int i,int parent[])
	{
		if(parent[i]==-1)
			return i;

		else

			return parent[i]=find_set(parent[i],parent);
	}

	//here we will be doing the union by rank(rank is the number of elements in the set) 
	void union_set(int a,int b,int parent[],int rank[])
	{
		int s1=find_set(a,parent);
		int s2=find_set(b,parent);

		//we first see if they are not in the same set already

		if(s1!=s2)
		{
			//here we will check the rank who has a greater rank
			
			if(rank[s1]<rank[s2])
			{
				parent[s1]=s2;
				rank[s2]+=rank[s1];
			}
			else
			{
				parent[s2]=s1;
				rank[s1]+=rank[s2];
			}
		}
	}

	bool contains_cycle()
	{
		int *parent=new int[V];
		int *rank=new int[V];

		for(int i=0;i<V;i++)
		{
			parent[i]=-1;  // It means that all the elements are different sets
		}

		for(int i=0;i<V;i++)
		{
			rank[i]=1;  // Each is a different set with the number of elements as 1
		}

		for(auto x:l)
		{
			int a=x.first;
			int b=x.second;

			int s1=find_set(a,parent);
			int s2=find_set(b,parent);

			if(s1!=s2)
			{
				union_set(s1,s2,parent,rank);
			}
			else
				return true;
		}

		delete [] parent;
		delete [] rank;

		return false;
	}


};

int main()
{
	Graph g(4);

	g.add_edge(0,1);
	g.add_edge(1,3);
	g.add_edge(3,2);
	g.add_edge(3,1);

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