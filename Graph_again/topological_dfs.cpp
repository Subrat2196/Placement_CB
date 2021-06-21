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
		// mp[y].push_back(x);
		
	}

	void dfs_helper(map<T,int> &vis,T node,list<T> &ordering)
	{
		vis[node]=1;
		
		for(auto mbr:mp[node])
		{
			if(!vis[mbr]){
				dfs_helper(vis,mbr,ordering);
			}
		}

		ordering.push_front(node);

		// ordering.push_front(node);


	}
	void dfs_tsort()
	{
		map<T,int> visited;
		list<T> ordering;

		for(auto x:mp)
		{
			T node=x.first;
			visited[node]=0;
		}

		
		// Here what we do is initiate a dfs call for each vertex if its not visited, since topological sort can start from any place
		for(auto x:mp)
		{
			T node=x.first;	
		
			if(!visited[node])
			{
				dfs_helper(visited,node,ordering);
			}
		}

		//finally print the list

		for(auto node:ordering)
		{
			cout<<node<<" ";
		}

	}


};



int main()
{

	Graph<string> g;

	g.add_edge("Python","Data Preprocessing");
	g.add_edge("Python","Pytorch");
	g.add_edge("Python","ML");
	g.add_edge("Data Preprocessing","ML");
	g.add_edge("Pytorch","DL");
	g.add_edge("ML","DL");
	
	g.dfs_tsort();

	return 0;

}