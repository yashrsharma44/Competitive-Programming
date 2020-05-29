#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	if(n <= m){

		ll ans = 1;
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(i!=j){
					ans = ((ans * abs(a[i] - a[j])) % m);
				}
			}
		}

		cout<<(ans%m)<<endl;

	} else {
		cout<<0<<endl;
	}

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
