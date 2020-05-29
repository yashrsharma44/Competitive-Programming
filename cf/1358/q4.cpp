#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,x;
	cin>>n>>x;

	vector<ll> d;
	vector<ll> cumu;
	ll nn = n;
	ll sumd = 0;
	cumu.push_back(0);
	while(nn--){
		ll vl;
		cin>>vl;
		sumd+=vl;
		// if(cumu.size() > 0){
		cumu.push_back(cumu[cumu.size()-1] + vl);
		// } else {
		// 	cumu.push_back(vl);
		// }
		d.push_back(vl);
	}

	vector<ll> prefix(n+1, 0);

	for(ll i=1;i<=n;i++){

		ll sum = (d[i-1]* (d[i-1] + 1)) / 2;
		prefix[i] = prefix[i-1] + sum;

	}
	reverse(prefix.begin(), prefix.end());
	reverse(cumu.begin(), cumu.end());
	ll maxSum = -1;
	for(ll i=0;i<cumu.size()-1;i++){

		ll pos = lower_bound(cumu.rbegin()+i, cumu.rend(), cumu[i]-x) - cumu.rbegin();
		pos = cumu.size() - pos - 1;
		maxSum = max(maxSum, prefix[i] - prefix[pos]);
		if(cumu[i] - cumu[pos] < x){
			ll start = x;
			for(;start<=cumu[pos];start++){
				maxSum+=start;
			}
		}
	}
		
	cout<<maxSum<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
