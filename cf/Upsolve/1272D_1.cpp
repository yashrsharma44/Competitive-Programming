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

	vector<ll> l(n, 1), r(n, 1);
	// l[0] = r[n-1] = 1;

	ll maxAns = 1;

	for(ll i=1;i<n;i++){

		if(a[i] > a[i-1]){
			l[i] = l[i-1] + 1;
			maxAns = max(maxAns, l[i]);
		} else {
			l[i] = 1;
		}
	}

	for(ll i=n-2;i>=0;i--){

		if(a[i+1] > a[i]){
			r[i] = r[i+1] + 1;
			maxAns = max(maxAns, r[i]);
		} else {
			r[i] = 1;
		}
	}

	 // max(l[n-1], r[0]);

	for(ll i=1;i<n-1;i++){

		if(a[i-1] < a[i+1]){
			maxAns = max(maxAns, l[i-1] + r[i+1]);
		}

	}

	cout<<maxAns<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}

}