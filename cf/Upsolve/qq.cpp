#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define itc ll t;cin>>t;while(t--)
#define otc ll t=1;while(t--)
#define ll long long int
#define ld long double
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define fi first
#define se second
#define ull unsigned long long int
#define memset(arr) memset(arr, 0, sizeof(arr));
bool sortinrev(const pair<ll, ll> &a, const pair<ll, ll> &b)
{return (a.fi > b.fi);}
int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll n;
	cin >> n;
	ll ar[n];
	for (ll i = 0; i < n; i++)
		cin >> ar[i];

	if (n == 1)
	{cout << ar[0]; return 0;}

	ll pos = 0;
	ll pre[n];
	ll suff[n];

	pre[0] = ~ar[0];
	for (ll i = 1; i < n; i++)
	{
		pre[i] = (~ar[i] & pre[i - 1]);
	}
	suff[n - 1] = ~ar[n - 1];
	for (ll i = n - 2; i >= 0; i--)
	{
		suff[i] = (~ar[i] & suff[i + 1]);
	}
	ll maxi = ar[0] & suff[1];
	for (ll i = 1; i < n - 1; i++)
	{

		ll val = (pre[i - 1] & suff[i + 1])& ar[i];
		if (val >= maxi)
		{	
			cout<<val<<endl;
			maxi = val;

			pos = i;
		}
	}
	cout << endl;
	if ((pre[n - 2]&ar[n - 1]) > maxi)
		pos = n - 1;

	swap(ar[0], ar[pos]);

	for (ll i = 0; i < n; i++)
		cout << ar[i] << " ";
	cout << endl;

	return 0;

}