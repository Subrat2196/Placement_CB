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

	void dfs_helper(map<T,int> &vis,T src)
	{
		vis[src]=1;
		cout<<src<<" ";

		for(auto mbr:mp[src])
		{
			if(!vis[mbr])
				dfs_helper(vis,mbr);
		}
	}
	void dfs(T src)
	{
		map<T,int> visited;

		for(auto x:mp)
		{
			T node=x.first;
			visited[node]=0;
		}

		dfs_helper(visited,src);
			


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

	g.dfs(0);

	return 0;

}