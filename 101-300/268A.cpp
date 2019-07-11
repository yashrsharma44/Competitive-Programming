#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,count=0;

	cin>>n;
	int list1[n],list2[n];

	int i;
	for(i=0;i<n;i++)
	{
		cin>>list1[i];
		cin>>list2[i];
	}

	int j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(list1[i]==list2[j])
			{
				count+=1;
			}
		}

	}

	cout<<count;
}