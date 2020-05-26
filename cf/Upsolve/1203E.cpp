
#include <bits/stdc++.h>
#define ll long long int

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

	sort(a.rbegin(), a.rend());

	ll count=0;
	ll cur = a[0]+2;
	for(ll i=0;i<n;i++){

		if(cur > a[i] + 1 && a[i] + 1 > 0){
			cur = a[i]+1;
			// break;
		} else if(cur > a[i] && a[i] > 0){
			cur = a[i];
		} else if(cur > a[i] - 1 && a[i] - 1 > 0){
			cur = a[i] - 1;
		} else {
			continue;
		}
		// cout<<cur<<endl;
		count++;
	}

	cout<<count<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}