#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;


int main()
{

	queue <char> q;
	unordered_map <char,int> umap;

	//take a running stream of characters until a dot comes

	char ch;
	cin>>ch;

	while(ch!='.')
	{
		//logic will go here
		//insert the char in queue and insert in frequency map

		q.push(ch);
		umap[ch]++;

		//query part -> here we need to look at the front of the queue 

		while(!q.empty())
		{
			char element=q.front();

			if(umap[element]>1)
			{
					q.pop();
				
			}
			else
			{
				cout<<element<<" ";
				break;		
			}
		}

		if(q.empty())
		{
			cout<<"-1"<<endl;
		}

		cin>>ch;
	}

	// unordered_map <char,int> :: iterator iter;

	// for(iter=umap.begin();iter!=umap.end();iter++)
	// {
	// 	cout<<(*iter).first<<"->"<<(*iter).second<<endl;
	// }




return 0;

}