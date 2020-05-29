#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool check(ll mid, vector<ll> a, ll k){

	ll sum=0;
	ll n = a.size();
	for(ll i=(n/2);i<a.size();i++){
		
		if(mid > a[i]){
			sum+=mid-a[i];
		}
	}

	return sum <= k;

}

void solve(){

	ll n,k;
	cin>>n>>k;
	ll nn = n;
	vector<ll> a;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	sort(a.begin(), a.end());
	
	ll l = 1, r = 2e9+1;

	while(l<r){

		ll mid = l + (r - l) / 2;
		if(check(mid, a, k)){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	
	cout<<r-1<<endl;

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
