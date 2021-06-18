#include <iostream>
#include <vector>
#include <queue>
#include<cstring>

using namespace std;


class Person
{

public:
	string name;
	int age;

	Person() //The empty constructor
	{

	}

	Person(string s,int a)
	{
		name=s;
		age=a;
	}

};

class PersonCompare
{
public:

	bool operator()(Person A,Person B)  //Here if you are making a comparator class, it is compulsory that you do
	{									//operator overloading of round brackets
		return A.age>B.age;
	}  
};





int main()
{
	int n;
	cin>>n;

	priority_queue<Person,vector<Person>,PersonCompare> pq;   //Here we need to compare the person but the priority queue dont know how to compare two Person therefore 
	// we need to create another class that will compare two functions(instead of greater<int>)
	//Therefore now instead of a comparator function we need a comparator class to be compared,since stl accepts a class here

	//That class must have the operator () overloaded inside it

	// Person p; then p(name,age) -> Here we cant do this due to the fact that constructor is called only once and when we create the object 
	// Then only we need to initialise the object

	for(int i=0;i<n;i++)
	{
		string name;
		int age;
		cin>>name>>age;
		Person pr(name,age);  //Here we are creating every time a new instance of person
		pq.push(pr); 
	}
	// Priority queeus are an advantage when using top k elements
	int k=3;
	cout<<endl;

	for(int i=0;i<k;i++)
	{
		Person p=pq.top();
		cout<<p.name<<" "<<p.age<<endl;
		pq.pop();
	}

	//Here we can also change the comparator to get the top 3 people

	return 0;



}