#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n;
	cin>>n;

	long long list[n];

	long long i;

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	// Bare minimum, for playing everyone, we need to have max of the rounds played 
	// by each people
	long long sum=0;

	long long max=list[0];
	for(i=0;i<n;i++)
	{
		if(max<list[i]){
			max=list[i];
		}
		sum+=list[i];
	}

	long long val;
	// cout<<max<<"U";
	if(sum % (n-1) == 0){val=(sum/(n-1));}
	else
	val = (sum/(n-1)) + 1;

	if(val< max)
		{val=max;}

	cout<<val;
}