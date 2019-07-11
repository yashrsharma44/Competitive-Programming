#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int list1[n];
	int list2[n];
	int list3[n];

	int i;
	for(i=0;i<n;i++)
	{
		cin>>list1[i];
		cin>>list2[i];
		cin>>list3[i];
	}

	int sum1=0,sum2=0,sum3=0;

	for(i=0;i<n;i++)
	{
		sum1+=list1[i];
		sum2+=list2[i];
		sum3+=list3[i];
	}

	if(sum1==0 && sum2==0 && sum3==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}