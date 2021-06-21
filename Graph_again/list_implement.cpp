#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template <typename T> 
class Graph
{
	unordered_map<T,list<pair<T,int>>> umap;

public:

	void add_edge(T x,T y,int distance,bool undir)
	{

		umap[x].push_back(make_pair(y,distance));

		if(undir)
			umap[y].push_back(make_pair(x,distance));

	}

	void print()
	{
		for(auto x:umap)
		{
			T city=x.first;       //It is the city name e.g A,B,C,D
			list<pair<T,int>> nbrs=x.second;  //It is the neighbours 			

			cout<<city<< " -> ";
			for(auto y:nbrs)
			{
				T dest=y.first;
				int dist=y.second;

				cout<<"("<<dest<<","<<dist<<")";
			}

			cout<<endl;

		}

	}

};



int main()
{
	Graph <string> g;
	g.add_edge("A","B",20,true);
	g.add_edge("B","D",30,true);
	g.add_edge("A","C",10,true);
	g.add_edge("C","D",40,true);
	g.add_edge("A","D",50,false);

	g.print();

	return 0;
}