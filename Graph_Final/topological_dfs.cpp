#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class graph
{
	//here we are creating using an array list
	int V;
	list<int> *l;

public:

	// we will create a constructor 

	graph(int V)
	{
		this->V=V;
		l=new list<int>[V];
	}

	void add_edge(int x,int y)
	{
		l[x].push_back(y);
	}


	void topological_sort()
	{
		// The first step is to make the vector of indegrees

		// vector<int> *indegree;

		// indegree=new vector<int>[V];

		vector<int> indegree(V,0);

		queue<int> q;

		for(int i=0;i<V;i++)
		{
			for(auto x:l[i])
			{
				indegree[x]++;
			}
		}

		vector<int> visited(V,0);

		for(int i=0;i<V;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
				visited[i]=1;
			}
		}

		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			cout<<node<<" ";

			for(auto x:l[node])
			{
				indegree[x]--;

				if(indegree[x]==0)
					q.push(x);				
			}
		}
	}
};


int main()
{

	graph g(6);

	g.add_edge(0,2);
	g.add_edge(1,2);
	g.add_edge(1,4);
	g.add_edge(4,5);
	g.add_edge(2,5);
	g.add_edge(2,3);

	g.topological_sort();

	return 0;


}


