#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
	int v;
	//Let us take an array list due to the fact that we have been given from 0 to N-1
	list<int> *l;

public:

	Graph(int v)
	{
		this->v=v;
		l=new list<int>[v];
	}

	void add_edge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs_helper(int src,queue<int> &q,vector<int> &vis)
	{

		q.push(src);
		vis[src]=1;
		

		while(!q.empty())
		{
			int element=q.front();
			cout<<element<<" ";
			q.pop();

			for(auto x:l[element])
			{
				if(vis[x]==0)
				{
					q.push(x);
					vis[x]=1;
				}
			}
		}
	}

	void bfs(int src)
	{

		queue<int> q;
		vector<int> visited(v,0);
		bfs_helper(src,q,visited);

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

	g.bfs(0);


}