#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
	//First define the data members
	int V;
	//We will be making a array list for the graph
	list<int> *l;

public:

	//Create the constructor

	Graph(int V)
	{
		this->V=V;
		l=new list<int>[V];
	}


	void add_edge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(int src,vector<int> &vis)
	{
		vis[src]=1;
		cout<<src<<" ";

		for(auto nbr:l[src])
		{
			if(!vis[nbr])
			{
				dfs_helper(nbr,vis);
			}
		}
	}

	void dfs(int src)
	{	

		vector<int> visited(V,0);

		dfs_helper(src,visited);


	}



};


int main()
{

Graph g(6);

	g.add_edge(1,2);
	g.add_edge(0,1);
	g.add_edge(2,3);
	g.add_edge(3,0);
	g.add_edge(3,4);
	g.add_edge(4,5);


	g.dfs(0);


}