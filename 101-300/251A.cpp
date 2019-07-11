#include <bits/stdc++.h>

using namespace std;

int dist(int a, int b)
{
	return abs(b-a);
}

int main(){

	int n,d;
	cin>>n>>d;

	int list[n];
	int i,j;	
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	// Using two pointer technique

	int count=0;
	for(i=0,j=0;i<n&&j<n;)
	{
		if(dist(list[i],list[j])<=d)
		{
			if(j-i+1 >= 3)
			{
				count+= j-i+1 - 3 +1;
			}
			j+=1;
		}
		else if(dist(list[i],list[j])>d)
		{
			i+=1;	
		}
		
	}
	cout<<count;
}