#include <iostream>
#include<algorithm>
#include <string>
#include <cstring>
using namespace std;


int main()
{

	// Concatenation of strings

	string s1="Hello hero we are here ";
	string s2="World is here where are you ";

	s1.erase(4,5);

	cout<<s1<<endl;


	// finding a substring

	cout<<s2.find("ere")<<endl; //return the first index where it finds it

	//inserting a string

	s2.insert(13," and");
	cout<<s2<<endl;

	//substring of a string

	s2=s2.substr(0,13);
	cout<<s2<<endl;


	// string to integer

	string x="786";
	int val=stoi(x);
	cout<<val+14<<endl; 


	int y=786;
	string s=to_string(y)+"2";
	cout<<s<<endl;


	//sorting a string

	s.clear();
	s="sdalsdkjapdfoejfmba";

	sort(s.begin(),s.end());

	cout<<s<<endl;

	return 0;
}