#include<iostream>
#include <map>
using namespace std;


//Map is an associative array
int main()
{

	map <string,int> markmap;

	markmap["Subrat"]=50;
	markmap["khushboo"]=55;
	markmap["Swami"]=65;
	markmap["Nishant"]=70;

	map <string,int> :: iterator iter;

	markmap.insert({{"Gaurav",65},{"Vaibhav",70}});

	for(iter=markmap.begin();iter!= markmap.end();iter++)
	{
		cout<<(*iter).first<<" -> "<<(*iter).second<<"\n";
	}

	return 0;
}