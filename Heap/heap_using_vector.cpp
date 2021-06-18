#include <iostream>
#include <vector>
using namespace std;


class Heap
{
	vector<int> v;
	bool minheap;

	bool compare(int a,int b)
	{
		if(minheap)
		{
			return a<b;
		}
		else
		{
			return a>b;
		}
	}

	void heapify(int idx)
	{
		int left=2*idx;
		int right=2*idx+1;

		int min_idx=idx;
		int last=v.size()-1;
		//We can only compare the children if they exist , so for them to exist they should be less than equal to the last index;

		if(left<=last and compare(v[left],v[right]))    //Here we have already made the compare function for both the minheap and the maxheap
				min_idx=left;			// In this there is comparison of left child and root if left < root then min will be left
		
		if(right<=last and compare(v[right],v[min_idx]))  //Now this comparison is between the min we got from previous comparison and the 
				min_idx=right;         // And the right child if it exists and will find the minimum

		if(min_idx!=idx){				//Here we are checking that if the minimum index is not same as the index because if it will be same
			swap(v[min_idx],v[idx]);	// Then we need to stop as current root is smaller then left and right
			heapify(min_idx);			// Here we recursively call the heapify on the min_index as we have to check for the left and the
		}								// and right also whichever is smaller

	}

public:

	Heap(int default_size=10,bool type=true)
	{
		v.reserve(default_size);//Here the reserve means that the vector will not expand until the default size is filled
		v.push_back(-1); //since we need to start from index 1
		minheap = type;  //Type will tell if min heap or max heap,here we take by default min heap
	}

	void push(int d)
	{
		v.push_back(d);

		//we need to find the index in which we need to insert the element, it will be v.size()-1 as it starts from 0 which is blocked

		int idx=v.size()-1;
		int parent=idx/2;

		//here we heapify the child that is child ask the parent tell me am i right
		//Here we keep going up until we reach the root or we stop in some midway point

		// while(idx>0 and v[idx]>v[parent]), if we will write like this it will only be valid for min heap
		//Therefore we need to write a compare function here
		
		while(idx>1 and compare(v[idx],v[parent])) //Here we took idx>1 due to the fact that  
		{
			 swap(v[idx],v[parent]);
			 idx=parent;
			 parent=parent/2;	  
		}
	}

	int get_top()
	{
		return v[1]; //Either min heap or max heap the minimum or maximum will be at the root of the heap
	}

	void pop()
	{
		int last=v.size()-1;

		swap(v[1],v[last]);  //here we will swap the first and the last element 
		v.pop_back();    //here we will pop the last element after that
		heapify(1);    //Here we pass the index of the root for the heapify, which means at each step the parent will its children am i right
		//or not in the position, if right you return otherwise swap with the minimum of root,left child,right_child 
	}

	bool empty()
	{
		return v.size()==1;	
	}

	
};

int main()
{
	//Firstly create and object of the class Heap

	Heap h;
	int n;
	cout<<"Enter the number of numbers you want to keep in the heap";
	cin>>n;

	cout<<endl;

	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		h.push(no);
	}

	while(!h.empty())
	{
		cout<<h.get_top()<<" ";
		h.pop();
	}
	//Here we will give the initial size of the heap\
	//we will also give min or max heap what we want





}