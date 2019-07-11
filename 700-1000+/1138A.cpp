#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	cin>>n;
	long long list[n+1];

	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}	
	if(list[n-1] == 1)
	{
		list[n] = 2;
	}
	else{
		list[n] =1;
	}

	int type1=0;
	int type2=0;

	int prev = list[0];
	int curr_len=1;
	for(i=1;i<n+1;i++)
	{	
		if(list[i]==prev)
		{
			curr_len+=1;
		}
		else
		{
			
			if(prev == 1)
			{
				// cout<<curr_len<<"\n";
				type1 = max(type1, curr_len);
			}
			else if(prev==2)
			{	
				// cout<<curr_len<<"\n";
				type2 = max(type2, curr_len);
			}
			
			curr_len=1;
		}
		prev = list[i];

	}
	cout<<2*min(type1,type2);
}