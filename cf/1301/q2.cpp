#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;
	
	ll maxEl = -1;
	ll minEl = INT_MAX;

	while(nn--){
		ll vl;
		cin>>vl;
		maxEl = max(maxEl, vl);
		if(vl >= 0){
			minEl = min(minEl, vl);
		}
		a.push_back(vl);
	}

	if(minEl == INT_MAX && maxEl == -1){
		cout<<0<<" "<<0<<endl;
		return;
	}

	ll el = -1;

	ll sum = maxEl + minEl;
	if(sum % 2 == 0){
		el = sum / 2;
	} else {
		el = (sum+1) / 2;
	}

	ll maxDiff = 0;

	for(ll i=0;i<n;i++){
		if(a[i] == -1){
			a[i] = el;
		}
	}

	for(ll i=0;i<n-1;i++){
		maxDiff = max(maxDiff, abs(a[i]-a[i+1]));
	}

	cout<<maxDiff<<" "<<el<<endl;


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}