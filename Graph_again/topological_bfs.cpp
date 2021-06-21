#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Graph
{

public:
	int v;
	list<int> *l;

	Graph(int v)
	{
		this->v=v;
		l=new list<int>[v];
	}

	void add_edge(int x,int y)
	{
		l[x].push_back(y);
	}


	void topology(int v)
	{
		// 1 -> The 1st step will be to find all the elements having indegree as 0

		//For this initially set all the indegrees to 0 in a vector

		vector<int> indegree(v,0);

		// after this we calculate the indegrees for all the nodes in the indegree vector

		for(int i=0;i<v;i++)
		{
			for(auto x:l[i])
			{
				indegree[x]++;
			}
		}

		//Now we will apply bfs and add all the elements with indegree 0;

		queue<int> q;
		for(int i=0;i<v;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}

		//Start removing elements from the queue

		while(!q.empty())
		{
			int node=q.front();
			cout<<node<<" ";
			q.pop();
		
		//Iterate over the neighbours of that node and reduce their indegree by 1

			for(auto nbr:l[node])
			{
				indegree[nbr]--;
				if(indegree[nbr]==0)
				{
					q.push(nbr);
				}
			}
		}

	}


};


int main()
{

	Graph g(6);

	g.add_edge(0,2);
	g.add_edge(1,2);
	g.add_edge(1,4);
	g.add_edge(4,5);
	g.add_edge(2,5);
	g.add_edge(2,3);
	g.add_edge(3,5);

	g.topology(6);

 	return 0;
}