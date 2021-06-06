#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;

template<typename T>
class Graph
{

	map <T,list<T>> mp;
public:

	void add_edge(int x,int y)
	{

		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void dfs_helper(T src,map<T,bool> &visited)
	{
		cout<<src<<" ";
		visited[src]=true;

		for(auto x:mp[src])
		{
			if(!visited[x])
			{
				dfs_helper(x,visited);
			}

		}



	}

	void dfs(T src)
	{
		
		map<T,bool> visited;

		for(auto p:mp)
		{
			T node=p.first;
			visited[node]=false;
		}
					
		dfs_helper(src,visited);



	}

};


	int main()
	{
		Graph<int> g;

		g.add_edge(0,1);
		g.add_edge(1,2);
		g.add_edge(2,3);
		g.add_edge(3,4);
		g.add_edge(4,5);
		g.add_edge(3,0);

		g.dfs(1);
		return 0;
	}