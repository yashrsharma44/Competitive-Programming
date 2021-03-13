#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

int ask(int l, int r)
{

	if (l >= r)
		return -1;

	cout << "? " << l << " " << r << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

void solve()
{

	int n;
	cin >> n;

	if (n == 2)
	{
		cout << "? 1 2\n";
		int x;
		cin >> x;
		if (x == 1)
			cout << "! 2\n";
		else
			cout << "! 1\n";
		return;
	}

	// Lets search smax in [l, r). Once we know, we can check if max lies left to smax or right. If [1, smax] doesn't return smax,
	// max lies to the right of smax. We can then search of the range [smax, m] where the max lies. Return the smallest possibe m which
	// would contain the position of max.

	int smax = ask(1, n);
	int pos = ask(1, smax);
	if (smax != pos)
	{
		// max lies to the right
		int l = smax-1, r = n + 1;
		while (r - l > 1)
		{
			int m = (l + r) >> 1;
			if (ask(smax, m - 1) == smax)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}

		cout << "! " << l << endl;
		return;
	}
	else
	{
		// max lies to the left
		int l = 0, r = smax + 1;
		while (r - l > 1)
		{
			int m = (l + r) >> 1;
			if (ask(m+1, smax) == smax)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}

		cout << "! " << r << endl;
		return;
	}
}

int32_t main()
{

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while (t--)
	{
		solve();
	}
}
