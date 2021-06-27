#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main()	
{
	string s="ashnadlsdjajgfahbjfal";

	//Convert it to upper case
	// we know ascii value of a is 97 and A is 65, therefore we have a difference of 32 here

	// for(int i=0;i<s.size();i++)
	// {
	// 	if(s[i]>='a' and s[i]<='z')
	// 	{
	// 		s[i]=s[i]-32;
	// 	}
	// }

	transform(s.begin(),s.end(),s.begin(),::toupper);	
	cout<<s<<endl;

	transform(s.begin(),s.end(),s.begin()+5,::tolower);	
	cout<<s<<endl;
	return 0;
}