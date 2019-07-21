#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){

	int r, c,j;

	cin>>r>>c;

	vector<int> row(r, 0);
	vector<int> col(c, 0);

	int i=0;
	for(i=0;i<r;i++)
	{
		string a;
		cin>>a;
		for(j=0;j<c;j++)
		{
			
			if(a[j]=='S')
			{
				row[i]=1;
				col[j]=1;
			}
		
		}
	}
	// cout<"YAY";

	int count=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if (row[i]==0 || col[j]==0)
			{
				count+=1;
			}
		}
	}

	cout<<count;
}