#include <iostream>
#include<vector>
#include <queue>
#include <cstring>

using namespace std;


class Fun
{
public:

	void operator()(string s)
	{
		cout<<"Here we have a functor "<<s<<endl;
	}

};



int main()
{

	Fun f;

	f("C++ ");

return 0;
}
