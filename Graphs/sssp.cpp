#include <iostream>
#include <list>
#include <map>
#include <queue>
#include<climits>

using namespace std;

template<typename T>
class Graph
{
	map<T,list<T>> mp;

public:

	void add_edge(int x,int y)
	{
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void sssp(T src)
	{
		map<T,int> distance; 
		queue<T> q;

		// all the other nodes will have infinite distance

		for(auto x:mp)
		{
			T node=x.first;
			distance[node]=INT_MAX;

		}
		
		q.push(src);
		
		distance[src]=0;
	

		while(!q.empty())
		{
			T element=q.front();
			q.pop();
			//cout<<element<<" ";
			for(auto x:mp[element])
			{
				if(distance[x]==INT_MAX)
				{
					q.push(x);
					distance[x]=distance[element]+1;
				}
			}

		}

		//Print distance of each node
		for(auto x:distance)
		{
			T node=x.first;
			int d =x.second;
			cout<<"Node "<<node<<" at a distance "<<d<<" from the source"<<"\n"; 
		}
	}
};


int main()
{
	Graph<int> g;

		g.add_edge(0,1);
		g.add_edge(0,2);
		g.add_edge(1,3);
		g.add_edge(3,2);
		g.add_edge(2,4);
		

		g.sssp(3);


	return 0;
}