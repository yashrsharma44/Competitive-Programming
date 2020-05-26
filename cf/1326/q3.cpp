#include <bits/stdc++.h>

#define MOD 998244353
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;
	vector<ll> b;
	vector< pair<ll,ll> > a;
	ll nn = n;
	ll i=0;
	while(nn--){
		ll vl;
		cin>>vl;
		b.push_back(vl);
		a.push_back(make_pair(vl, i++));
	}

	sort(a.begin(), a.end());
	// Max possible value is top k elements
	ll sum = a[n-1].first;
	ll ans  = 1;
	// ll prevValue = a[n-1].second;
	for(ll i=n-2;i>=n-k;i--){
		sum+=a[i].first;
		// ans = (ans * abs(a[i].second - prevValue)) % MOD;
		// prevValue = a[i].second;
	}

	ll prevValue = -1;
	i=0;
	for(;i<n;i++){

		if(b[i] > (n-k)){
			prevValue = i;
			i++;
			break;
		}
	}
	for(;i<n;i++){

		if(b[i] > (n-k)){
			ans = (ans * abs(i - prevValue))%MOD;
			prevValue = i;
		}
	}

	cout<<sum<<" "<<ans<<endl;


}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}