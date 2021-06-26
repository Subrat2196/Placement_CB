#include<iostream>
#include <string>
#include <cstring>
using namespace std;


int main()
{

	// Concatenation of strings

	string s1="Hello ";
	string s2="World ";

	string s;
	s=s1+s2;
	cout<<s<<endl;

	string s3="Subrat ";

	string s4=s.append(s3);

	cout<<"String s5 is -> ";
	cout<<s4<<endl;

	// Clear string

	cout<<"String s5 after clear is-> ";
	s4.clear();
	cout<<s4<<endl;

	//Comparison of strings

	 s1.clear();
	 s2.clear();

	 s1="Hellp";
	 s2="Hellq";

	 if(s1.compare(s2) == 0)
	 	cout<<"s1 and s2 are equal"<<endl;
	 else if (s1.compare(s2)>0)
	 	cout<<"s1 is lexicographically greater than s2"<<endl;
	 else
	 	cout<<"s2 is lexicographically greater than s1"<<endl;


	 //Empty or not

	 s1.clear();
	 if(s1.empty())
	 	cout<<"Empty String"<<endl;


	return 0;
}