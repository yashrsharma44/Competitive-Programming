#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,i;
	cin>>n>>m;

	vector <int> list(n);

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	// Choosing integers which needs to be increased/or decreased
	// Keep a counter whether an integer needs to be decreased or increased

	vector <int> count(n,0);
	for(i=0;i<n;i++)
	{
		if(list[i]<m-1)
		{
			count[i]=1;
		}
		else if(list[i]>=m-1)
		{
			count[i]=-1;
		}
	}

	// Once we have the count, try to iterate through each element
	// and find whether the current element is less than the right
	// most element

	// If yes, then move, if not then try to decrease it by the counter
	// If decrement not possible, try to increase the right element

	list[n] = 1e5;
	count[n] = 0;
	int right;
	for(i=0;i<n;i++)
	{
		right=list[i+1];
		if(list[i]<=right)
		{
			continue;
		}
		else if(list[i]>right)
		{
			if(count[i]==-1)
			{
				list[i] = (list[i]+1)%m;
			}
			else if(count[i]==1)
			{
				if(count[i+1]==1)
				{
					list[i+1] = (list[i+1]+1)%m;
				}
			}
		}
	}

	// Print
	for(i=0;i<n;i++)
		{cout<<list[i];}

}