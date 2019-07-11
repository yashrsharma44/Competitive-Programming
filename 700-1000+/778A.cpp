#include <bits/stdc++.h>

// #include <string>
using namespace std;

int main()
{
	string t, p;
	getline(cin, t);
	getline(cin, p);

	p.shrink_to_fit();
	t.shrink_to_fit();

	int len = t.capacity();
	int plen = p.capacity();
	int i;
	int list[len];
	for(i=0;i<len;i++)
	{	
		cin>>len[i];
	}

	// Start with iterating through all the letters and mark off the first occurence and keep a count
	int count[plen];
	int j=0;
	for(i=0;i<len&&j<plen;i++)
	{
		if(p[j] == t[i])
		{
			count[j] = i;
			j+=1;
		}
	}
}