#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include<vector>
#include <queue>
#include <climits>

using namespace std;

class Graph
{
	int V;
	//array of lists we can make or we can make hashmap of keys and values as list of pairs

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

	//Here we need to find the single source shortest path




	void sssp(int src)
	{
		
		//we need a node to start, we need a distance vector to store the distances and we need a queueu to do level order traversal

		queue<int> q;

		//here what we did is initialized the vector distance to INT_MAX since at the starting we dont know
		vector<int> dist(V,INT_MAX);

		q.push(src);

		// Here we made the distance of the src as 0 due to tha fact that its our source
		dist[src]=0;

		while(!q.empty())
		{

			int node=q.front();
			q.pop();

			//Here we are checking all the adjacent

			for(auto x:l[node])
			{
				if(dist[x]==INT_MAX)
				{
					q.push(x);
					dist[x]=dist[node]+1;

				}
			}

		}

		for(int i=0;i<V;i++)
		{
			cout<<i<<" -> "<<dist[i]<<endl;
		}
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


	g.sssp(0);



}
