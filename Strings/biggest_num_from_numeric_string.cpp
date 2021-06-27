#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()	
{
	string s="87248235640";

	sort(s.begin(),s.end(),greater<int>());
	cout<<s<<endl;
	return 0;
}