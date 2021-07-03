#include <iostream>
#include <climits>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
	int V;
	list<int> *l;

public:

	Graph(int V)
	{
		this->V=V;
		l=new list<int>[V];
	}


	void add_edge(int x,int y)
	{
		l[x].push_back(y);
			}


	bool dfs_helper(int src,vector<int> visited,vector<int> st)
	{

		visited[src]=1;
		st[src]=1;

		for(auto x:l[src])
		{
			if(visited[x]==1 and st[x]==1)  //here we can skip the visited[x]==1 since if st[x]==1 it means it must have already been visieted too
				return true;

			else if(visited[x]!=1)
			{
				bool cycle=dfs_helper(x,visited,st);   //here you will keep a boolean here too
				if(cycle==true)
					return true;
			} 
		}

		st[src]=0;


		return false;
	}

	bool iscycle(int src)
	{	
		//here we are using dfs approach to find if cycle present or not

		vector<int> visited(V,0);

		vector<int> st(V,0);

		bool ans=dfs_helper(src,visited,st);

		return ans;

	}

};


int main()
{
		
	Graph g(7);

	g.add_edge(0,1);
	g.add_edge(1,5);
	g.add_edge(5,6);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(3,4);
	g.add_edge(4,5);
	g.add_edge(4,2);

	if(g.iscycle(0))
	{
		cout<<"cycle"<<endl;
	}
	else
	{
		cout<<"No cycle"<<endl;
	}


	
	return 0;


}