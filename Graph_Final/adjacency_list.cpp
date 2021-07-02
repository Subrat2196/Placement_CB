#include <iostream>
#include <list>
using namespace std;


//We are creating a graph using array list

class Graph
{
	//we will have number of vertices 
	int V;
	list<int> *l;  //Here if we just write list<int> l ; it will create a single list but we are making a pointer on an array of list

public:

	//we will give a constructor

	Graph(int V)
	{
		this->V=V;

		l=new list<int>[V];
	}

	void add_edge(int x,int y) //here from x to y we have the edge, if we have undirected then both ways
	{
		l[x].push_back(y);
		l[y].push_back(x);  
	}


	void print_graph()
	{
		//Here because we need to print for each index and we know the vertices are from 0 to V-1

		for(int i=0;i<V;i++)
		{
			cout<<"Vertex "<<i<<" --> ";
			for(auto x:l[i])
			{
				cout<<x<<"  ";
			}

			cout<<endl;
		}

	}

};





int main()
{

	Graph g(4);   //created the object and constructor got called..

	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(2,1);
	g.add_edge(2,3);
	g.add_edge(0,3);
	g.add_edge(1,3);
	

	g.print_graph();


	return 0;


}