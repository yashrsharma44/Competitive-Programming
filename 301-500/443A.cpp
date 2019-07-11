#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	// cout<<str;
	
	int i;
	// str.erase('{');
	// str.erase('}');
	// str.erase(',');
	// str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
	int len=str.length();

	string alpha="abcdefghijklmnopqrstuvwxyz";
	vector <int> list(alpha.length(), 0);
	int j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<alpha.length();j++)
		{
			if(alpha[j]==str[i])
			{
				list[j]=1;
			}
		}
	}

	int sum=0;
	for(i=0;i<alpha.length();i++)
	{
		sum+=list[i];
	}

	cout<<sum;
}