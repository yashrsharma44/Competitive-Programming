#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int i;

	// int end = str.end();

	// cout<<str.find("WUB");
	while(str.find("WUB")!=string::npos)
	{
		str.replace(str.find("WUB"), sizeof("WUB")-1, " ");
	}
	cout<<str;

}