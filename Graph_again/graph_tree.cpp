#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Graph
{
	int v;
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

	bool flag=false;

	bool tree_or_not()
	{
		queue<int>q;

		bool *visited=new bool[v];

		int* parent=new int[v];

		for(int i=0;i<v;i++)
		{
			visited[i]=false;
			parent[i]=i;
		}

		int src=0;
		q.push(src);
		visited[src]=1;

		while(!q.empty())
		{
			int element=q.front();
			q.pop();

			for(auto nbr:l[element])
			{
				if(visited[nbr]==true and parent[element]!=nbr)
				{
					flag=true;
				}
				else if(!visited[nbr])
					{
						visited[nbr]=true;
						parent[nbr]=element;
						q.push(nbr);
					}
				}
			}

		return flag;
	}
};


int main()
{
	Graph g(4);

	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(3,1);
	g.add_edge(2,3);
	
	bool val=g.tree_or_not();

	if(val)
		cout<<"Loop exists";
	else
		cout<<"Loop doesnt exist";


	return 0;
}