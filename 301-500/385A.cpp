#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,c;

	cin>>n>>c;

	vector <int> list(n);

	int i;

	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	int max=0;

	for(i=0;i<n-1;i++)
	{
		if(((list[i]-list[i+1])>0))
		{
			if((list[i]-list[i+1]-c > max)){
				max = list[i]-list[i+1]-c;
			}
		}
	}

	cout<<max;
}