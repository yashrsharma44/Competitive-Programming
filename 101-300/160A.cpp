#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int list[n];
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
		sum+=list[i];
	}

	sort(list, list+n, greater<int>());
	int sum2=0;
	int count2=0;
	for(i=0;i<n;i++)
	{
		if(sum2<=(double)(sum/2))
		{
			count2+=1;
			sum2+=list[i];
		}
	}

	if(sum2>(double)sum/2)
	{
		cout<<count2;
	}
	else if((double)sum2==(double)(sum/2))
	{
		cout<<count2-1;
	}
	


}