
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector< vector<ll> >val(200011, vector<ll>());
	for(ll el : a){
		ll cnt=0;
		while(el > 0){
			val[el].push_back(cnt);
			cnt++;
			el/=2;
		}
	}

	ll ans=1e9;

	for(ll i=1;i<=200011;i++){

		sort(val[i].begin(), val[i].end());
		if((ll)(val[i].size()) < k){
			continue;
		}
		ans = min(ans, accumulate(val[i].begin(), val[i].begin()+k, 0ll));

	}

	cout<<ans<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}