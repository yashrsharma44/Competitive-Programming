#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;

	int i=0,j=0;

	int len=s.length();
	int l;
	if(len%2==0)
	{l = len/2;}
	else
	{l = len/2 +1;}
	char list[l];
	for(i=0,j=0;i<len;i+=2,j++)
	{
		list[j] = s[i];
	}

	sort(list, list+l);
	for(i=0;i<l;i++)
	{
		if(i!=l-1)
		{
			cout<<list[i]<<"+";
		}
		else
		{
			cout<<list[i];
		}
	}
}