#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	// we need to make an array of list
	//if we make a single list we make it as list <int> l;
	// if we need to make an array list we make it as   list <int> l[10];
	// we can make it dynamically since we dont know the value of V at runtime

	list<int> *l;
 
public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];

	}

	void add_edge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);

	}

	void print_adj_list()
	{
		//Iterate over all the vertices

		for(int i=0;i<V;i++)
		{
			cout<<"Vertex "<<i<<"->";	 	
			for(int x:l[i])      // for loop for each list in the array
			{
				cout<<x<<",";
			}

			cout<<"\n";
		}
	}

	
};


int main()
{
	// Graph g[4];

	Graph g(4); //Calling the constructor of the graph

	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,2);
	g.add_edge(2,3);

	g.print_adj_list();

	return 0;
}