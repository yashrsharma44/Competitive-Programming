#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m;
	cin>>n;
	cin>>m;

	int list[n];
	int i;

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	
	}	

	// Max
	int max = -1;

	for(i=0;i<n;i++)
	{
		if(list[i]>max)
		{
			max = list[i];
		}

	}
	// Min
	int mm = m;
	int j=0;
	for(;m>0;m--)
	{
		// Inner loop for finding the min value
		int min_ind = 0;
		for(j=0;j<n;j++)
		{
			if(list[j]<list[min_ind])
			{
				min_ind = j;
			}
		}
		list[min_ind] += 1;
	}

	int max_min =list[0];
	for(i=1;i<n;i++)
	{
		if(list[i]>max_min)
			{max_min = list[i];}
	}
	
	int real_max = max + mm;
	cout<<max_min<<" "<<real_max;


}