#include <bits/stdc++.h>
#define ll int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	if(n == 1){
		cout<<a[0]<<endl;
		return;
	}

	vector<ll> prefix(n, 0), suffix(n, 0);
	prefix[0] = ~a[0];
	suffix[n-1] = ~a[n-1];

	for(int i=1;i<n;i++){
		prefix[i] = prefix[i-1] & (~a[i]);
	}

	for(int i=n-2;i>=0;i--){
		suffix[i] = suffix[i+1] & (~a[i]);
	}

	ll mx = a[0] & suffix[1];
	ll pos= 0;

	for(ll i=1;i<n-1;i++){

		ll val = prefix[i-1] & a[i] & suffix[i+1];
		// cout<<val<<endl;
		if(mx <= val){
			mx = val;
			pos = i;
		}
	}

	if(mx < (a[n-1] & prefix[n-2])){
		pos = n-1;
		mx = a[n-1] & prefix[n-2];
	}

	swap(a[0], a[pos]);
	for(ll el : a){
		cout<<el<<" ";
	}
	cout<<endl;

	// cout<<mx<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}

}