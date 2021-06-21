#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{

	int V;

	//Here we need an Array of Lists

	list<int> *l;

public:

	//Here we have a graph constructor that will accept the number of vertices
	Graph(int V)
	{
		this->V=V;
		l=new list<int>[V];
	}


	void add_edge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void print()
	{
		//Iterate over all the vertices

		for(int i=0;i<V;i++)
		{
			cout<<i<<"->";

			for(auto x:l[i])
			{
				cout<<x<<",";
			}

			cout<<"\n";
		}

	}

};


int main()
{

	Graph g(4); //Here we are calling the constructor
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(0,2);
	g.add_edge(2,3);


	g.print();

	return 0;

}