#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;

	cin>>n>>m;
	int list[m];

	int i;
	for(i=0;i<m;i++)
	{
		cin>>list[i];
	}
	sort(list, list+m);

	int mini=10000;

	for(i=0;i<=m-n;i++)
	{
		mini=min(mini,list[i+n-1]-list[i]);
	}
	if(mini==10000)
	{
		cout<<0;
	}
	else
	{
		cout<<mini;
	}

}