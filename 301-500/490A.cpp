#include <bits/stdc++.h>

using namespace std;

struct triplet{
	int f=0;
	int s=0;
	int t=0;
};

int main()
{
	int n;
	cin>>n;
	vector <int> list(n);
	triplet val;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>list[i];
	}

	for(i=0;i<n;i++)
	{
		if(list[i]==1)
		{
			val.f+=1;
		}
		else if(list[i]==2)
		{
			val.s+=1;
		}
		else if(list[i]==3)
		{
			val.t+=1;
		}
	}

	int ll[3];
	ll[0]=val.f;
	ll[1]=val.s;
	ll[2]=val.t;

	int mn = min(ll[0],min(ll[1],ll[2]));

	if(val.f==0||val.s==0||val.t==0)
	{
		cout<<0;
	}
	else
	{
		cout<<mn<<endl;
		for(int j=0;j<mn;j++){
			int p1,p2,p3;
			for(i=0;i<n;i++)
			{
				if(list[i]==1)
				{
					p1=i+1;
					
				}
				else if(list[i]==2)
				{
					p2=i+1;
					
				}
				else if(list[i]==3)
				{
					p3=i+1;
					
				}
			}
			list[p1-1]=list[p2-1]=list[p3-1]=-1;
			cout<<p1<<" "<<p2<<" "<<p3;
			cout<<endl;
		}

	}
}