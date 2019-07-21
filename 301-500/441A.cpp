#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,v;
	cin>>n>>v;

	vector< vector <int> > list(n);

	int i=0,j;
	for(i=0;i<n;i++)
	{
		int ik;
		cin>>ik;
		list[i] = vector <int>(ik+1);
		list[i][0] = ik;
		int j;
		for(j=1;j<ik+1;j++)
		{
			cin>>list[i][j];
		}
	}

	int output[n];
	int count=0;
	for(i=0;i<n;i++)
	{
		for(j=1;j<list[i][0]+1;j++)
		{
			if(v > list[i][j])
			{
				count+=1;
				output[i]=i+1;
				break;
			}
			else
			{
				output[i]=0;
			}
		}
	}

	cout<<count<<endl;

	if(count)
	{for(int i=0;i<n;i++)
		{	
			if(output[i] !=0){
			cout<<output[i]<<" ";
			}
		}
	}

}