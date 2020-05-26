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
	sort(a.begin(), a.end());
	ll minDiff = 10000;
	for(ll i=1;i<n;i++){
		minDiff = min(minDiff, a[i] - a[i-1]);
	}
	cout<<minDiff<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	// t=1;

	while(t--){
		solve();
	}

}