#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll lcm(ll x, ll y){

	return (x*y) / __gcd(x,y);
}

void solve(){

	ll n;
	cin>>n;

	ll nn=n;
	vector<ll> arr;
	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	vector<ll> postgcd(n,1);
	ll run_gcd = arr[n-1];
	for(ll i=n-1;i>=0;i--){
		run_gcd = __gcd(run_gcd, arr[i]);
		postgcd[i] = run_gcd;
	}

	vector<ll> pair_gcd(n-1,1);
	for(ll i=0;i<n-1;i++){
		pair_gcd[i] = (arr[i] * postgcd[i+1]) / postgcd[i];
	}

	ll ans = pair_gcd[0];
	for(ll el : pair_gcd){
		ans = __gcd(ans, el);
	}

	cout<<ans<<endl;

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
