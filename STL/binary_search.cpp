#include <iostream>
#include <algorithm>

using namespace std;



int main()
{

	int arr[]={1,10,11,15,15,15,15,16,19,19,19,22,23,27};
	int n=sizeof(arr)/sizeof(int);
	
	//Here we are using the binary search to search the elements if sorted array

	//Binary search returns if present or not
	cout<<"Give the key "<<endl;

	int key;
	cin>>key;


	bool present=binary_search(arr,arr+n,key);

	if(present)
		cout<<"element present"<<endl;
	else
		cout<<"element not present"<<endl; 

	cout<<"Now you need to find the index of first occurence of the element"<<endl;

	auto it=lower_bound(arr,arr+n,key);

	int element=it-arr;

	cout<<"Lower Bound of "<<key<<" is "<<(it-arr)<<endl;

	cout<<"Now you need to find the element that is strictly greater than the key"<<endl;

	auto it2=upper_bound(arr,arr+n,key);

	int element1=it2-arr;
	cout<<"Upper Bound of "<<key<<" is "<<(it2-arr)<<endl;


	cout<<"Now we need to find the frequency of the key"<<endl;


	cout<<(element1-element)<<endl;
	cout<<endl;


	return 0;

}

