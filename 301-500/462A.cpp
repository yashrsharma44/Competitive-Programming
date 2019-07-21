#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	cin>>n;

	int i,j;

	vector< vector<char> > list(n+2, vector<char>(n+2));
	for(i=1;i<n+1;i++)
	{
		int j;
		for(j=1;j<n+1;j++)
		{
			cin>>list[i][j];
		}
	}

	int flag=0;

	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			int count=0;
			if(list[i-1][j]=='o')count++;
			if(list[i+1][j]=='o')count++;
			if(list[i][j+1]=='o')count++;
			if(list[i][j-1]=='o')count++;

			if(count%2!=0)
			{
				flag=1;
				break;
			}
		}
	}

	if(!flag)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}