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
	void connected_components()
	{
		map<T,int> visited;

		for(auto x:mp)
		{
			T node=x.first;
			visited[node]=0;
		}

		
		// Here what we do is initiate a dfs call for each vertex if its not visited
		int cnt=0;
		for(auto x:mp)
		{
			T node=x.first;	
		
			if(!visited[node])
			{
				cout<<"component "<<cnt<<" -> ";
				dfs_helper(visited,node);
				cnt++;
				cout<<endl;
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
	g.add_edge(6,7);
	g.add_edge(7,8);

	g.connected_components();

	return 0;

}