#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;

	cin>>n;

	vector < pair<int,int> > list(n);
	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i].first>>list[i].second;
	}

	sort(list.begin(),list.end());

	// Assume that Alex is wrong, we need 1 example to prove him right
	int flag=0;

	for(i=0;i<n-1;i++)
	{
		if(list[i+1].second - list[i].second < 0)
		{
			flag=1;
		}
	}

	if(flag==0){
		cout<<"Poor Alex";
	}
	else
	{
		cout<<"Happy Alex";
	}
}