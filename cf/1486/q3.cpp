#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

int ask(int l, int r)
{
	if (l >= r)
	{
		return -1;
	}

	cout << "? " << l << " " << r << endl;
	cout.flush();
	int idx;
	cin >> idx;
	return idx;
}

void solve()
{

	int n;
	cin >> n;

	// if(n == 2){
	// 	cout<<"? 1 2\n";
	// 	int x; cin>>x;
	// 	if(x == 1) cout<<"! 2\n";
	// 	else cout<<"! 1\n";
	// 	return;
	// }

	int l = 1; //  
	int r = n+1;

	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		int smax = ask(l, r-1);

		// l < smax < m < r
		// max could be between [l, smax], [smax, m], [m, r]
		// if we query between [l, m], and find smax == secondmax, max lies in [l, m] else should be [m, r]
		if (smax < m)
		{

			if (ask(l, m-1) == smax)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		else
		{
			if (ask(m, r-1) == smax)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}
	}

	cout << "! " << l << endl;
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
