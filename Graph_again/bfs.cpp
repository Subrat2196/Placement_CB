#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

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

	void bfs(T src)
	{
		queue<T> q;
		map<T,int> visited;

		q.push(src);
		visited[src]=1;

		while(!q.empty())
		{
			T node=q.front();
			q.pop();
			cout<<node<<",";
			for(auto nbr:mp[node])
			{
				if(visited[nbr]==0){
					q.push(nbr);
					visited[nbr]=1;
				}
			}
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

	g.bfs(0);

	return 0;

}