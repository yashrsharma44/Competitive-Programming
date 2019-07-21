#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin>>n>>k;

	vector <int> list(n);
	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}	

	// sort(list.begin(), list.end());

	int count=0;

	for(i=0;i<n;i++)
	{
		if(list[i] <= (5 - k))
		{
			count+=1;
		}
	}
	// 

	cout<<count/3;

}