#include <iostream>
using namespace std;

class point
{
private:
	int x;
	int y;

public:

	point():x(0),y(0)
	{

	}

	point(int x1,int x2):x(x1),y(x2)
	{

	}


	void print()
	{
		cout<<x<<"  "<<y<<endl;
	}


};

int main()
{

	point p(10,15);
	p.print();



	return 0;
}