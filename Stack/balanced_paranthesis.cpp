#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

bool isbalance(char *str,int n)
{
	stack <char> s;

	for(int i=0;i<n;i++)
	{
		if(n==true)
			return true;

		char ch=str[i];

		if(ch=='(')
		{
			s.push(ch);
		}

		else if(ch==')')
			{
				if(s.empty() or s.top()!='(')
				{
					return false;
				}

				s.pop();
			}

		}


		return s.empty();
		// if(s.empty())
		// {
		// 	return true;
		// }

		// return false;



}


int main()
{

	char str[]="((a+b)+(c-d+f))";
	int n=strlen(str);

	if(isbalance(str,n)==true)
	{
		cout<<"Balanced Paranthesis";
	}
	else
	{
		cout<<"Unbalanced Paranthesis";
	}
	return 0;


}