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
	
	int connected_components()   //we can start with any node since we just need to find the connected components
	{
		
		map<T,bool> visited;

		for(auto p:mp)
		{
			T node=p.first;
			visited[node]=false;
		}

		int count=0;
					
		//Iterate over all vertices and initiate a DFS call if a vertex is not visited

		for(auto n:mp)
		{
			T node=n.first;
			if(!visited[node])
			{
				cout<<"component "<<count<<"-->";
				dfs_helper(node,visited);
				count++;
			}
		}
		cout<<endl;
		return count;
	}

};


	int main()
	{
		Graph<int> g;

		g.add_edge(0,1);
		g.add_edge(1,2);
		g.add_edge(2,3);
		g.add_edge(0,3);
		g.add_edge(0,4);
		g.add_edge(5,6);
		g.add_edge(6,7);
		g.add_edge(8,8);
		

		cout<<g.connected_components()<<endl;
		return 0;
	}