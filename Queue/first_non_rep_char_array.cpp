#include <iostream>
#include <queue>

using namespace std;


int main()
{

	queue <char> q;
	int freq[27]={0};  //here a will be stored at 0 index, b at 1 similarly upto z 
					  //You will get an integer index if you subtract 'a' from the character since its seen as ASCII value 
					  // That is how u map a character with an index
	//take a running stream of characters until a dot comes

	char ch;
	cin >> ch;

	while(ch!='.')
	{
		//logic will go here
		//insert the char in queue and insert in frequency map

		q.push(ch);
		
		freq[ch-'a']++;

		//query part -> here we need to look at the front of the queue 

		while(!q.empty())
		{
			int idx=q.front()-'a';

			if(freq[idx]>1)
			{
					q.pop();
				
			}
			else
			{
				cout<<q.front()<<" ";
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