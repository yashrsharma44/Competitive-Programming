#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> b;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		b.push_back(vl);
	}

	vector<ll> a(n,0);
	a[0] = b[0];
	ll x_i = 0;
	for(ll i=1;i<n;i++){

		x_i = max(x_i, a[i-1]);
		a[i] = b[i] + x_i;

	}

	for(ll el : a){
		cout<<el<<" ";
	}
	cout<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}