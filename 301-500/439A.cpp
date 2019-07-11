#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n,d;

	cin>>n>>d;
	vector<int> list(n);

	int i=0;
	int sum=0;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
		sum+=list[i];
	}
	if((10*(n-1))+sum > d)
	{
		cout<<-1;
	}
	else
	{
		int num1 = (n-1)*2;
		
		num1 += (d - ((10*(n-1))+sum))/5;

		cout<<num1;
	}
}