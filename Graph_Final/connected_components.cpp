#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;


class Graph
{
	unordered_map<int,list<int> > umap;

public:
	Graph()
	{

	}

	void add_edge(int x,int y)
	{
		umap[x].push_back(y);
		umap[y].push_back(x);
	}

	void dfs_helper(int element,map<int,int> &visited)
	{
		cout<<element<<" ";
		visited[element]=1;

		for(auto x:umap[element])
		{
			if(!visited[x])
			{
				dfs_helper(x,visited);
			}
		}
	}

	int connected()
	{
		//here the concept is that we will run dfs or bfs for each vertex that is not visited

		map<int,int> visited;

		for(auto x:umap)
		{
			int element=x.first;
			visited[element]=0;
		}

		int cnt=0;
		
		for(auto x:umap)
		{
			int element=x.first;
				
		
			if(!visited[element])
			{
				cout<<"component "<<cnt;
				dfs_helper(element,visited);
				cnt++;
				cout<<endl;
			}
		}
		
		return cnt;

	}



};


int main()
{

	Graph g;

	g.add_edge(1,2);
	g.add_edge(0,1);
	g.add_edge(2,3);
	g.add_edge(3,0);
	g.add_edge(6,6);
	g.add_edge(4,5);

	cout<<g.connected()<<endl;

	return 0;




}