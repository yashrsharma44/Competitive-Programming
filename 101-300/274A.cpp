#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;

	cin>>n>>k;

	vector <int> list(n);

	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	sort(list.begin(),list.end());
	vector <bool> count(n,false);

	int set_size=0;

	for(i=0;i<n;i++)
	{
		if(!count[i])
		{
			set_size+=1;
			if(binary_search(list.begin(), list.end(), k*list[i]))
				{
					// int val = list[i]*k
					int index = lower_bound(list.begin(), list.end(), k*1LL*list[i])-list.begin();
					count[index] = true;
					
				}
		}
	}

	cout<<set_size;

}