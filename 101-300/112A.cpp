#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int l1 = s1.length();
	int l2 = s2.length();

	int flag=0;
	int i;
	for(i=0;i<l1;i++)
	{
		if((int)s1[i] <=90 && (int)s1[i] >=65)
		{
			s1[i] = (char)((int)s1[i]+32);
		}
		if((int)s2[i] <=90 && (int)s2[i] >=65)
		{
			s2[i] = (char)((int)s2[i]+32);
		}

		if((int)s2[i] < (int)s1[i])
		{
			if(i==l1-1)
			{
				flag=1;
			}
			cout<<1;
			break;
		}
		else if((int)s2[i] > (int)s1[i])
		{
			if(i==l1-1)
			{
				flag=1;
			}
			cout<<-1;
			break;
		}

	}

	if(i==l1 && !flag)
	{
		cout<<0;
	}
}