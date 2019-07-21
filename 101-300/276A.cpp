#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k;

	cin>>n>>k;

	int i;

	vector< pair<int, int> > list(n);

	for(i=0;i<n;i++)
	{
		cin>>list[i].first>>list[i].second;

	}

	vector <int> joy(n);

	for(i=0;i<n;i++)
	{
		if(list[i].second - k < 0)
		{
			joy[i] = list[i].first;
		}
		else
		{
			joy[i] = list[i].first - (list[i].second - k);
		}
	}

	long long max = -9999999999999999;
	for(i=0;i<n;i++)
	{
		if(joy[i]>max)
		{
			max = joy[i];
		}
	}

	cout<<max;

}