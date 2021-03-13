#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{

	bool isPos = false;
	int a, b;
	cin >> a >> b;
	a = b + a;
	if (a >= 15 && b >= 8)
	{
		cout << 1 << " ";
		isPos = true;
	}
	else if (a >= 10 && b >= 3)
	{
		cout << 2 << " ";
		isPos = true;
	}
	else if (a >= 3)
	{
		cout << 3 << " ";
		isPos = true;
	}
	else
	{
		cout << 4 << endl;
	}
	cout << endl;
}

int32_t main()
{

	int t = 1;
	// cin>>t;

	while (t--)
	{
		solve();
	}
}