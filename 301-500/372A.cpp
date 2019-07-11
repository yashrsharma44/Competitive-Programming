#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n;
	cin>>n;

	vector <int> list(n);

	int i;

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	sort(list.begin(),list.end());

	// Get the result using two pointer technique

	int j=n/2;
	int count_pair=0;
	for(i=0;i<n/2&&j<n;j++)
	{
		if(list[i]*2<=list[j])
		{
			count_pair+=1;
			i+=1;
		}

	}

	cout<<n-count_pair;

}