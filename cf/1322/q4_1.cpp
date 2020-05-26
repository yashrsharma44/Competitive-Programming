#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define sz size()

// #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>void __f(const char* name, Arg1&& arg1){cout<<name<<" : "<<arg1<<"\n";}
// template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args)
// {const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" , ";__f(comma+1, args...);} 
// #define traceloop(x,a) { cerr<<#a<<": "; for(ll ix=0;ix<x;ix++) cerr<<a[ix]<<" "; cerr<<endl; }

int main()
{
	ios::sync_with_stdio(0);
	int i, j, k, n;
	cin >> n;
	vector<int> a(n);
	for(i=0;i<n;++i)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll ans = 0;
	for(k=0;k<27;++k)
	{
		vector<int> b(n);
		for(i=0;i<n;++i)
			b[i] = a[i] % (1 << (k+1));
		
		sort(b.begin(), b.end());

		ll cnt = 0;
		for(i=0;i<n;++i)
		{
			int l = lower_bound(b.begin()+i+1, b.end(), (1 << k) - b[i]) - b.begin();
			int r = lower_bound(b.begin()+i+1, b.end(), (1 << (k+1)) - b[i]) - b.begin();
			cnt += r - l;

			l = lower_bound(b.begin()+i+1, b.end(), (1 << (k+1)) + (1 << k) - b[i]) - b.begin();
			cnt += n - l;
		}

		ans += (cnt % 2) *1LL* (1 << k);
	}

	cout << ans << "\n";

	return 0;
}