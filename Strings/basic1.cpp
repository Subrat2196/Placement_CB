#include<iostream>
#include <string>
#include <cstring>
using namespace std;


int main()
{
	string s(5,'n');

	cout<<s<<endl;

	string str;

	cout<<"using cin ->"<<endl;

	cin>>str;
	cout<<str<<endl;

	cin.get();
	string st;

	cout<<"Using getline "<<endl;
	getline(cin,st);
	
	cout<<st;



	return 0;
}