#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main()	
{
	string s="abcbsbsbdbsbabcsldsndlmlskdl";

	map<char,int> map;

	for(int i=0;i<s.length();i++)
	{
		map[s[i]]++;
	}

	
	int max=0;
	for(auto x: map)
	{
		if(max<x.second)
		{
			max=x.second;
		}
	}

	for(auto x: map)
	{
		if(x.second==max)
		{
			cout<<x.first<<endl;
			break;
		}
	}
	cout<<max<<endl;

	return 0;
}