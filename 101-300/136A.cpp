#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,i;
	cin>>n;

	int list[n];

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	int list2[n];

	for(i=0;i<n;i++)
	{
		list2[list[i]-1] = i+1;
	}

	for(i=0;i<n;i++)
	{
		if(i!=n-1){
		cout<<list2[i]<<" ";
		}
		else
		{
			cout<<list2[i];
		}
	}
}