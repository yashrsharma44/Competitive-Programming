#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void solve()
{

	int p, a, b, c;
	cin >> p >> a >> b >> c;
	int a1 = (p + a - 1) / a;
	int a2 = (p + b - 1) / b;
	int a3 = (p + c - 1) / c;

	int ans = min({a - p % a, b - p % b, c - p % c, p % a, p % b, p % c});
	cout << ans << endl;
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	// t = 1;

	while (t--)
	{
		solve();
	}
}
