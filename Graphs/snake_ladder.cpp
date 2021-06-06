#include <iostream>
#include <list>
#include <map>
#include <queue>
#include<climits>

using namespace std;

template<typename T>
class Graph
{
	map<T,list<T>> mp;

public:

	void add_edge(int x,int y)
	{
		mp[x].push_back(y);
		//mp[y].push_back(x); Since edges are to a single direction
	}

	int snake_ladder(T src,T dest)
	{
		map<T,int> distance;
		map<T,T> parent; 
		queue<T> q;

		// all the other nodes will have infinite distance

		for(auto x:mp)
		{
			T node=x.first;
			distance[node]=INT_MAX;

		}
		
		q.push(src);
		
		distance[src]=0;
		parent[src]=src;
	

		while(!q.empty())
		{
			T element=q.front();
			q.pop();
			//cout<<element<<" ";
			for(auto x:mp[element])
			{
				if(distance[x]==INT_MAX)
				{
					q.push(x);
					distance[x]=distance[element]+1;
					parent[x]=element;
				}
			}

		}

		
		//we can calculate the path of dest from dest to src

		T temp=dest;

		while(temp!=src)
		{
			cout<<temp<<" <-- ";
			temp=parent[temp];
		}

		cout<<src<<endl;
		
		
		// To destination node only we want

		return distance[dest];

		// //Print distance of each node
		// for(auto x:distance)
		// {
		// 	T node=x.first;
		// 	int d =x.second;
		// 	cout<<"Node "<<node<<" at a distance "<<d<<" from the source"<<"\n"; 
		// }
	}
};


int main()
{
	Graph<int> g;

	int board[50]={0};

	//    snakes/ladders -> we can also calculate it explicitly i.e if the ladder starts from 2 and goes till 15 then ladder[2]=15-2

	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=10;
	board[32]=-2;
	board[34]=-22;
	// e.g if we have are at 1 and we connect to 2 and there is a ladder from 2 to 15 then we do as : 
	// 1 ----> (1(for where you are standing) + 1(die throw) + 13), therefore it becomes 1->15


	//Add all edges to the graph


	for(int i=0;i<=36;i++)   
	{
		for(int dice=1;dice<=6;dice++)  //at every i we can throw a dice between 1 and 6
		{
			int j=i+dice;   //j is the node where we want to reach we still need to add the jump to it
			 j += board[j];

			 if(j<=36)    // this function wont be called when the value of i is 36, because they will have a value atleast 37
			 {
			 	g.add_edge(i,j);
			 }
		}
	}

	g.add_edge(36,36); 



	g.snake_ladder(0,36); // Here we need to give the source and the destination // rather than printing the shortest path to every node
				  // We just need the shortest path to the destination


	return 0;
}