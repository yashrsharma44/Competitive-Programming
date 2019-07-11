#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> list(n);

	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}
	int eve=0, odd=0;

	for(i=0;i<n;i++)
	{
		if(list[i]%2==0)
			{eve+=1;}
		else
			{odd+=1;}

	}

	if(odd>eve)
	{
		for(i=0;i<n;i++)

		{
			int flag=1;
			if(list[i]%2==0)
			{
				flag=0;
				cout<<i+1;
			}
			if(i!=n-1&&flag==0)
			{cout<<" ";}

		}

	}
	else
	{
		for(i=0;i<n;i++)

		{
			int flag=1;
			if(list[i]%2!=0)
			{
				flag=0;
				cout<<i+1;
			}
			if(i!=n-1&&flag==0)
			{cout<<" ";}

		}
	}
}