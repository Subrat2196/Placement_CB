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

	void bfs(T src)
	{
		map<T,bool> visited;
		queue<T> q;

		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T top=q.front();
			q.pop();
			cout<<top<<"  ";

			for(int nbr:mp[top])
			{
				if(!visited[nbr])
				{
					visited[nbr]=true;
					q.push(nbr);
				}
			}
		}
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
		

		g.bfs(0);
		return 0;
	}