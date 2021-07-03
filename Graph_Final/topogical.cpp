#include <iostream>
#include <list>
#include <map>

using namespace std;

template<typename T>
class Graph
{
	map<T,list<T>> mp;

public:

	//here we will add the edges and it will be a directed graph

	void add_edge(T x,T y)
	{
		mp[x].push_back(y);
	}

	
	void dfs_helper(T element,map<T,int> &visited,list<T> &l)
	{
		visited[element]=1;
		for(auto nbr:mp[element])
		{
			
			if(!visited[nbr])
			{
				dfs_helper(nbr,visited,l);
			}
		}

		l.push_front(element);

	}

	//Here we will make a topological sort ordering

	void topological_sort()
	{

		map<T,int> visited;
		list<T> l;

		//Here we are making all the  
		for(auto x:mp)
		{
			T node=x.first;
			visited[node]=0;
		}

		for(auto x:mp)
		{
			T element=x.first;
			
			if(!visited[element])
			{
				dfs_helper(element,visited,l);

			}	
		}


		for(auto x:l)
		{
			cout<<x<<"  ";
		}
		
	}


};




int main()
{

	Graph<string> g;

	g.add_edge("Python","Data Preprocessing");
	g.add_edge("Python","Pytorch");
	g.add_edge("DataSet","FR");
	g.add_edge("Data Preprocessing","ML");
	g.add_edge("Pytorch","DL");
	g.add_edge("ML","DL");
	g.add_edge("Pytorch","DL");
	g.add_edge("DL","FR");

	g.topological_sort();
	return 0;
}