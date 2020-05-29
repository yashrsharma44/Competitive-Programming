#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	vector < vector <char> > list(n, vector <char>(n));

	int i,j;
	char c;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>list[i][j];
		}
	}

	c = list[0][0];

	// Check whether it forms an x

	int flag=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j || i+j==n-1)
			{
				if(list[i][j]!=c)
				{
					flag=1;
					break;
				}
			}
		}
	}

	// Check if all elements are same
	int count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(list[i][j]==c)
			{
				count+=1;
			}
		}
	}

	if(count==(n*n))
	{
		flag=1;
	}

	if(flag==1)
	{
		cout<<"NO";
	}
	else
	{
		int flag2=0;
		int mid = n/2;

		for(i=0;i<n;i++)
		{
			for(j=0;j<mid;j++)
			{
				if(list[i][j] != list[i][n-j-1])
				{
					flag2=1;
					break;
				}
			}
		}

		for(i=0;i<mid;i++)
		{
			for(j=0;j<n;j++)
			{
				if(list[n-i-1][j] != list[i][j])
				{
					flag2=1;
					break;
				}
			}
		}
		if(flag2){
			cout<<"NO";
		}
		else
		{
			cout<<"YES";
		}
	}

}