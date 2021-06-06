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

	void add_edge(T x,T y)
	{

		mp[x].push_back(y);
		// mp[y].push_back(x);  Here we only need a unidirectional edge
	}

	void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering)
	{
		// cout<<src<<" ";
		visited[src]=true;

		for(auto x:mp[src])
		{
			if(!visited[x])
			{
				dfs_helper(x,visited,ordering);
			}

		}

		ordering.push_front(src);



	}

	void dfs()
	{
		
		map<T,bool> visited;

		list <T> ordering;

		for(auto p:mp)
		{
			T node=p.first;
			visited[node]=false;
		}


		for(auto p:mp)
		{
			T node=p.first;
			if(!visited[node])
			{
				dfs_helper(node,visited,ordering);        //We will run it from  every node due to the reason that 
			}
		}
					
		for(auto l: ordering)
		{
			cout<<l<<endl;
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

		g.dfs();
		return 0;
	}