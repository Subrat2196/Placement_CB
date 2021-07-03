#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <set>
#include <climits>
using namespace std;

template<typename T>
class Graph
{

	unordered_map<T,list<pair<T,int>>> umap;

public:

	void add_edge(T x,T y,int wt)
	{
		umap[x].push_back(make_pair(y,wt));
		umap[y].push_back(make_pair(x,wt));
	}

	void print_graph()
	{
		for(auto x:umap)
		{
			T element=x.first;
			cout<<element<<"-->";

			list<pair<T,int>> l=umap[element];
			for(auto y:l)
			{
				cout<<"( "<<y.first<<" , "<<y.second<<")";
			}

			cout<<endl;

		}


	}


	void dijkstras(T src)
	{
		//here for dijkstra's we need a distance map in the first place that will keep the city name and the distances
		//here we will update this when we reduce our count
		// we will also have a set here which will contain a pair with node and distance, we will get our minm distance from here

		//step 1 - create a unordered map of node and distance and initialise it to infinite which is INT__MAX

		unordered_map<T,int> distance;
		unordered_map<T,T> parent;

		for(auto x:umap)
		{
			T element=x.first;
			distance[element]=INT_MAX;
			parent[element]="NULL";
		}

		//Step 2 -> create a set of pairs
		//Here one important thing that 'Set' sorts according to the first parameter therefore we need to give the distance as the first parameter

		set<pair<int,T>> s;

		distance[src]=0;
		parent[src]="NULL";

		//Make distance of source node as 0 and insert in the set

		s.insert(make_pair(0,src));


		//step 3 -> In this what we do is keep pushing in the set and popping the adjacents kind of like the BFS

		while(!s.empty())
		{
			//Now we need the first element in the set because it will have the minumum distance

			auto sp=*(s.begin());  //here it is again a very important step we got to know the use of iterators and iterator is an address therefore
									// set pair will be in the *address

			//Now we need to find the adjacents of the node in the set and see there adjacent distances

			T node=sp.second;
			int set_node_dist=sp.first;

			//Now since the distance has already been finalized therefore we erase it

			s.erase(s.begin());

			//Now we need to itrate over the current node
			for(auto x:umap[node])
			{
				//here it will traverse through all the adjacent of the node

				T adj=x.first;
				int adj_dist=x.second;

				if(distance[adj]>set_node_dist+adj_dist)
				{
					//here adj[distance] will INT_MAX in the start we will update it in set as well as distance map
					distance[adj]=distance[node]+adj_dist;
					// Now here we need to update the set
					//Here updation means that we need to erase the node after finding and add new dode with new distance

					// if(s.find(make_pair(adj)!=s.end())
					// {
					// 	s.erase(adj_dist,adj);
					// }

					if(s.find(make_pair(adj_dist,adj))!=s.end())
					{
						s.erase(make_pair(adj_dist,adj));
					}

					s.insert(make_pair(distance[adj],adj));
					parent[adj]=node;
				}
			}
		}

		for(auto x:distance)
		{
			cout<<x.first<<" --> "<<x.second<<endl;
		}

		cout<<endl;

		for(auto x:parent)
		{
			cout<<x.first<<" --> "<<x.second<<endl;
		}

	}

};


int main()
{
	Graph<string> g;

	g.add_edge("Dehradun","Delhi",20);
	g.add_edge("Dehradun","Jaipur",50);
	g.add_edge("Jaipur","Delhi",30);
	g.add_edge("Jaipur","Mumbai",70);
	g.add_edge("Mumbai","Bhopal",30);
	g.add_edge("Bhopal","Agra",80);
	g.add_edge("Agra","Delhi",55);
	

	g.dijkstras("Dehradun");


	return 0;
}




