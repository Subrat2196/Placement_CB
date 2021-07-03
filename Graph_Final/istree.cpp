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
		l[y].push_back(x);
	}

	bool istree(int src)
	{
		queue<int> q;
		vector<int> visited(V,0);

		vector<int> parent(V,-1);
		q.push(src);
		visited[src]=1;

		while(!q.empty())
		{
			int node=q.front();
			q.pop();

			for(auto x:l[node])
			{
				if(visited[x]==1 and parent[node]!=x)
				{
					return true;
				}
				else if(!visited[x])
				{
					q.push(x);
					visited[x]=1;
					parent[x]=node;
				}
			}

		}

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
	g.add_edge(3,4);

	if(g.istree(0))
	{
		cout<<"cycle"<<endl;
	}
	else
	{
		cout<<"No cycle"<<endl;
	}


	
	return 0;


}