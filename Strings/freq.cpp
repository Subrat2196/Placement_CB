#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main()	
{
	string s="abcbsbsbdbsbabcsldsndlmlskdl";

	int freq[26]={0};

	for(int i=0;i<s.size();i++)
	{
		freq[s[i]-'a']++;
	}

	char ans='a';

	int maxf=0;

	for(int i=0;i<26;i++)
	{
		if(freq[i]>maxf)
		{
			maxf=freq[i];
			ans=i+'a';
		}
	}

	cout<<ans<<" "<<maxf<<endl; 


	return 0;
}
