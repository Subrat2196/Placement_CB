#include <iostream>
#include <unordered_map>
#include<list>
#include <cstring>
using namespace std;


class Graph{

	int V;

	unordered_map <string,list<pair<string,int> > > umap;


public:

	void add_edge(string x,string y,bool bidir,int wt)
	{
		umap[x].push_back(make_pair(y,wt));
		if(bidir)
		{
			umap[y].push_back(make_pair(x,wt));
		}

	}

	void print_adj_list()
	{
		for(auto p: umap)    //iterating over map so we will get a key and value pair where the first is city and the second is the list
		{
			string city=p.first;

			list<pair<string,int>> l=p.second;

			cout<<"vertex "<<city<<" -> ";

			for(auto x:l)
			{
				string dest=x.first;
				int dist=x.second;
				cout<<"("<<dest<<","<<dist<<")";
			}
			cout<<"\n";

		}


	}


};

int main()
{
	Graph g;

	g.add_edge("A","B",true,20);
	g.add_edge("A","C",true,10);
	g.add_edge("B","D",true,30);
	g.add_edge("C","D",true,40);
	g.add_edge("A","D",false,50);

	g.print_adj_list();
	return 0;
}