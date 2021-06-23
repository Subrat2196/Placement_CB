#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Graph
{
	int v;
	list<int> *l;

public:

	Graph(int v)
	{
		this->v=v;
		l=new list<int>[v];
	}

	void add_edge(int x,int y)
	{
		l[x].push_back(y);
	}

	bool flag=false;

	bool cycle_helper(int node,bool *visited,bool *stack)
	{
		//visit a node
		visited[node]=true;
		stack[node]=true;

		for(int nbr:l[node])
		{
			//two cases
			if(stack[nbr]==true)
					return true;

			else if(visited[nbr]==false)
			{
				bool cycle_mila=cycle_helper(nbr,visited,stack);
				if(cycle_mila==true )
					return true;
			}
		}
		//leave a node
		stack[node]=false;
		return false;
	}

	bool contains_cycle()
	{
		bool *visited=new bool[v];
		bool *stack=new bool[v];

		for(int i=0;i<v;i++)
		{
			visited[i]=stack[i]=false;
		}
		return cycle_helper(0,visited,stack);

	}
};


int main()
{
	Graph g(7);

	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(2,3);
	g.add_edge(3,4);
	g.add_edge(4,5);
	g.add_edge(1,5);
	g.add_edge(5,6);
	g.add_edge(4,2);
	
	bool val=g.contains_cycle();

	if(val)
		cout<<"cycle exists";
	else
		cout<<"cycle doesnt exist";


	return 0;
}