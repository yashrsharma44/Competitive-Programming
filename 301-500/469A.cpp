#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	cin>>n;

	
	

	int p1,p2;
	cin>>p1;
	vector <int> X(p1);
	int i;
	for(i=0;i<p1;i++)
	{
		cin>>X[i];
	}
	cin>>p2;
	vector <int> Y(p2);
	for(i=0;i<p2;i++)
	{
		cin>>Y[i];
	}
	vector <int> list(n+1,0);

	for(i=0;i<p1;i++)
	{
		list[X[i]]=1;
	}
	for(i=0;i<p2;i++)
	{
		list[Y[i]]=1;
	}

	int flag=0;
	for(i=1;i<n+1;i++)
	{
		if(list[i]==0)
		{
			flag=1;
			break;
		}
	}
	// cout<<list;

	if(flag)
	{
		cout<<"Oh, my keyboard!";
	}
	else
	{
		cout<<"I become the guy.";
	}
}