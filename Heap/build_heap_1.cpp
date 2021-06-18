#include <iostream>
#include <vector>
using namespace std;



	void build(vector<int> &v)
	{
		for(int i=2;i<v.size();i++)
		{
			int idx=i;
			int parent=i/2;

			while(idx>1 and v[idx]>v[parent])
			{
				swap(v[idx],v[parent]);
				idx=parent;
				parent=parent/2;
			}
		}

	}

//here we will take a vector and then convert it to the max heap
int main()
{
	vector<int> v{-1,10,20,5,6,1,8,9,4};

	for(auto x:v)
	{
		cout<<x<<" ";
	}

	build(v);

	cout<<endl;
	for(auto x:v)
	{
		cout<<x<<" ";
	}



}