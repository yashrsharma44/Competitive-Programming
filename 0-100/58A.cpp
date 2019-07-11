# include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1;
	getline(cin, s1);

	int len = s1.length();
	string s2 = "hello";
	int i=0,j;

	for(i=0,j=0;i<len&&j<5;)
	{
		if(s1[i] == s2[j])
		{
			i+=1;
			j+=1;
		}
		else
		{
			i+=1;
		}
	}

	if(j==5)
	{
		cout<<"YES";

	}
	else
	{
		cout<<"NO";
	}
}