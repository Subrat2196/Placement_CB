#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
#include <climits>
using namespace std;

template<typename T>
class Graph
{
	map<T,list<T>> mp;
public:

	void add_edge(T x,T y)
	{
		mp[x].push_back(y);
		mp[y].push_back(x);
		
	}

	void sssp(T src)
	{
		queue<T> q;
		map<T,int> dist;

		q.push(src);
		
		for(auto x:mp)
		{
			T node=x.first;
			dist[node]=INT_MAX;
		}

		dist[src]=0;

		while(!q.empty())
		{
			T node=q.front();
			q.pop();

			for(auto nbr:mp[node])
			{
				if(dist[nbr]==INT_MAX)
				{
					q.push(nbr);
					dist[nbr]=dist[node]+1;
				}
			}
		}

		for(auto x:mp)
		{
			T node=x.first;
			cout<<node<<"->"<<dist[node]<<endl;
		}


	}

};



int main()
{

	Graph<int>g;

	g.add_edge(1,2);
	g.add_edge(1,0);
	g.add_edge(3,2);
	g.add_edge(3,0);
	g.add_edge(3,4);
	g.add_edge(4,5);

	g.sssp(0);

	return 0;

}