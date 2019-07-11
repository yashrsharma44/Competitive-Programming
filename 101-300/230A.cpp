#include <bits/stdc++.h>

using namespace std;

int main()
{
	int s, n;

	cin>>s>>n;

	vector< pair <int,int> > list(n);

	int i,flag=0;
	for(i=0;i<n;i++)
	{
		int xi, yi;

		cin>>xi>>yi;
		list[i].first=xi;
		list[i].second=yi;
		
	}

	sort(list.begin(), list.end());

	

	for(i=0;i<n;i++)
	{
		int xi = list[i].first;
		int yi=list[i].second;
		if(s>xi)
			{
				s+=yi;
			}
			else
			{
				flag=1;
				break;
			}
	}
	if(flag==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}