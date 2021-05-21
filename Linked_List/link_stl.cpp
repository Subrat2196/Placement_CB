#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l;

//init
	list<int> l1{1,2,7,6,5,4,3};

	//different datatypes

	list<string> l2{"litchi","mango","apple","guava","lemon","taramind","orange","guava","apple"};
	l2.push_back("pineapple");

	//Iterate over the list and print the data
	for(auto x:l2)
	{
		cout<<x<<"->";
	}

	l2.remove("apple");

	cout<<endl;

	for(auto x:l2)
	{
		cout<<x<<"->";
	}
// 	l2.sort();
// 	l2.reverse();

// 	for(auto x:l2)
// 	{
// 		cout<<x<<"->";
// 	}

// 	for(auto it=l2.begin();it!=l2.end();it++)
// 	{
// 		cout<<(*it)<<"->";
// 	}
// }
}