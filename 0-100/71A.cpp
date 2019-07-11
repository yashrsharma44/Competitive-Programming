#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int n;
	cin>>n;
	vector< string > list(n);
	int i;
	cin.ignore(n,'\n');
	for(i=0;i<n;i++)
	{
		
		getline(cin, list[i]);
	}



	for(i=0;i<n;i++)
	{
		string str = list[i];
		int len = str.length();
		if(len>10)
		{
			cout<<str[0] + std::to_string(len-2) + str[len-1]<<"\n";
		}
		else
		{
			cout<<str<<"\n";
		}
	}
	
}