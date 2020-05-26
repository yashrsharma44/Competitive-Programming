#include <bits/stdc++.h>
#define ll long long int

using namespace std;

pair<ll,ll> intersection(pair<ll,ll> p1, pair<ll,ll> p2){

	ll mx = max(p1.first, p2.first);
	ll mn = min(p1.second, p2.second);
	pair<ll,ll> ans = make_pair(mx, mn);
	return ans;
}

bool chk(set<ll> &st, ll k){

	vector<ll> v;
	for(ll el : st){
		v.push_back(el);
	}

	ll mn = v[0], mx = v[(ll)v.size()-1];
	for(ll i=1;i<(ll)(v.size()-1);i++){
		if(abs(v[i] - mn) <= k && abs(v[i] - mx)<= k){
			return true;
		}
	}

	return false;

}

void solve(){

	ll n,k;
	cin>>n>>k;

	vector<ll> arr;
	ll nn=n;
	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	ll abs_mn=LLONG_MAX,abs_mx=-1;
	vector < pair<ll,ll> > interval;
	for(ll i=0;i<n/2;i++){

		
		ll mn = min(arr[i], arr[n-i-1]);
		ll mx = max(arr[i], arr[n-i-1]);
		interval.push_back(make_pair(mn+1, mx+k));
		abs_mn = min({abs_mn, mn+1, mx+k});
		abs_mx = max({abs_mx, mn+1, mx+k});
	}

	pair<ll,ll> ans = make_pair(abs_mn, abs_mx);
	for(ll i=0;i<interval.size();i++){

		ans = intersection(ans, interval[i]);
	}

	map <ll,ll> mp;
	ll count = 0;
	ll mx = -1, mn = LLONG_MAX;
	for(ll i=0;i<n/2;i++){
		ll sm = arr[i] + arr[n-1-i];
		mp[sm]+=1;
		mx = max(mx, sm);
		mn = min(mn, sm);
	}

	ll minCount = n/2;
	for(ll i=0;i<n/2;i++){
		ll sm = arr[i] + arr[n-i-1];
		if(abs(sm - mx) <= k && abs(sm - mn) <=k){
			ll cnt = 0;
			if(mp[sm] > 1){
				cnt = (n / 2) - mp[sm] + 1;
			} else {
				cnt = (n/2) - mp[sm];
			}
			minCount = min(minCount, cnt);
		}
	}

	cout<<minCount<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
