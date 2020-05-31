#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(pair<ll,ll> &p1, pair<ll,ll> &p2){

	if(p1.second != p2.second){
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}

void solve(){

	ll n,I;
	cin>>n>>I;
	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	map<ll,ll> mp;
	for(ll el : a){
		mp[el]+=1;
	}

	ll finalDist = 1 << min(20ll, ((8*I) / n));
	if(finalDist >= mp.size()){
		cout<<0<<endl;
		return;
	}
	
	vector<ll> count;
	for(auto el : mp){
		count.push_back(el.second);
	}

	ll sum = 0;
	ll ans = INT_MAX;
	for(ll i=0;i<finalDist && i < count.size();i++){
		sum += count[i];
	}
	ans = min(ans, n - sum);
	for(ll i=finalDist;i<count.size();i++){
		sum += count[i] - count[i - finalDist];
		ans = min(ans, n - sum);
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
