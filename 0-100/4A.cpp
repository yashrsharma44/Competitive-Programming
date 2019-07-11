#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w;
	cin>>w;

	if(w%2!=0)
	{
		cout<<"NO";

	}
	else
	{
		int i,flag=0;
		for(i=1;i<w/2;i++)
		{
			if((w/2 - i)%2)
			{
				flag=1;
				cout<<"YES";
				break;
			}
		}
		if(!flag)
		{
			cout<<"NO";
		}
	}
}