#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int V;
	list<int> *l;  //This is by default private
public:

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

	bool dfs_helper(int src,int visited[],int parent)
	{
		visited[src]=1;

		for(auto x:l[src])
		{
			if(visited[x]==1 and parent!=x)
			{
				return true;
			}

			else if(!visited[x])
			{
				bool cycle=dfs_helper(x,visited,src);
				if(cycle)
				{
					return true;
				}
			}
		}

		return false;
	}


	bool iscycle(int src)
	{
		int parent=-1;  //here we dont need a parent array due to the fact that stack will take care of it

		int *visited=new int[V];

		for(int i=0;i<V;i++)
		{
			visited[i]=0;
		}

		bool ans=dfs_helper(src,visited,parent);  //cycle comes when it is already visited and parent[adjacent]!=src;

		if(ans)
			return true;


		return false;

	}


};

int main()
{

	Graph g(5);

	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,4);
	// g.add_edge(3,4);

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

