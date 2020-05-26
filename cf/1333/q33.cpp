#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	a.push_back(0);
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	ll totalSubArray = 0, mx = 0;
	map <ll,ll> mp;
	mp[0] = 0;
	ll sum = 0;
	for(ll i=1;i<=n;i++){
		sum+=a[i];

		if(mp.count(sum)){
			mx = max(mx, mp[sum]+1);
		}
		totalSubArray +=(i - mx);
		mp[sum] = i;
	}

	cout<<totalSubArray<<endl;
}

int main(){
	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}