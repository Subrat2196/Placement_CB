#include <iostream>
using namespace std;

class Point
{
private:

	int *ptr;

public:

	Point(int x)
	{
		ptr=new int(x);
	}


	Point(const Point &t)
	{
		int val=*(t.ptr);
		ptr=new int(val);
	}

	void set(int x)
	{
		*ptr=x;
	}


	
	void print()
	{
		cout<<*ptr<<"  "<<endl;
	}


};

int main()
{

	Point p1(10);
	Point p2(p1);
	p2.set(20);

	p1.print();
	p2.print();

	//here output came as 20 20 which is unexpected since we are only changing p2 but p1 also gets changed which is a problem

	//Here problem comes in dynamic memory allocation

	return 0;
}