#include <iostream>
#include <vector>
using namespace std;


void heapify(int idx,vector<int> &v)
{
	int left=idx*2;
	int right=idx*2+1;
	int min_idx=idx;
	int last=v.size()-1;

	if(left<=last and v[left]>v[idx])
	{
		min_idx=left;		
	}

	if(right<=last and v[right]>v[min_idx])
	{
		min_idx=right;
	}

	if(min_idx!=idx)
	{
		swap(v[idx],v[min_idx]);
		heapify(min_idx,v);
	}
}


void heapify_for_heapsort(int idx,vector<int> &v,int n) 
{
	int left=idx*2;
	int right=idx*2+1;
	int min_idx=idx;
	int last=n-1;

	if(left<=last and v[left]>v[idx])
	{
		min_idx=left;		
	}

	if(right<=last and v[right]>v[min_idx])
	{
		min_idx=right;
	}

	if(min_idx!=idx)
	{
		swap(v[idx],v[min_idx]);
		heapify_for_heapsort(min_idx,v,n);
	}
}

void build_heap(vector<int> &v)
{
	int n=(v.size()-1);
	for(int i=n/2;i>=1;i--)
	{
		heapify_for_heapsort(i,v,v.size());		
	}
}


void heap_Sort(vector<int> &v)
{
	build_heap(v);

	int n=v.size();

	//remove n-1 elements from the heap
	
	while(n>1)
	{
		swap(v[1],v[n-1]);
		//Here we are removing element from the heap but in vector it is present

		n--;
		heapify_for_heapsort(1,v,n);  //here we pass the n also since it does not run on the entire array
	}
}

int main()
{
	vector<int> v{-1,10,20,5,6,1,8,9,4};

	for(auto x:v)
	{
		cout<<x<<" ";
	}

	heap_Sort(v);

	cout<<endl;
	for(auto x:v)
	{
		cout<<x<<" ";
	}

return 0;

}