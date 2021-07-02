#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template<typename T>

class Graph
{
	int V;
	//Here we will be giving the data that in not in between 0 to V-1 can be anything

	unordered_map<T,list<pair<T,int>>> umap;

public:	

	//here we will create a constructor
	Graph(int V)
	{
		this->V=V;
	}

	void add_edge(T x,T y,int wt,bool bidir)
	{
		//Yes here push_back works for the unordered map
		umap[x].push_back(make_pair(y,wt));
		
		if(bidir)
		{
			umap[y].push_back(make_pair(x,wt));
		}
	}

	void print_graph()
	{
		for(auto x:umap)
		{
			auto element=x.first;

			cout<<element<<" --> ";

			for(auto y:x.second)
			{
				cout<<"("<<y.first<<","<<y.second<<")";
			}

			cout<<endl;

		}

	}


};



int main()
{
	//here wer will give the number of vertices
	//the edges that are connected
	//bidirectional or unidirectional



	Graph<string> g(4);

	g.add_edge("A","C",10,true);
	g.add_edge("A","B",20,false);
	g.add_edge("A","D",50,false);
	g.add_edge("D","C",40,true);
	g.add_edge("B","D",30,false);

	g.print_graph();


	return 0;


}