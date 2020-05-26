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

	vector<ll> prefix(n, 0);

	for(ll i=1;i<n;i++){
		prefix[i] = a[i] - a[i-1];
	}

	vector<ll> peak(n, 0);

	for(ll i=1;i<n-1;i++){

		if(a[i] > a[i-1] && a[i] > a[i+1]){
			peak[i] = peak[i-1] + 1;
		} else {
			peak[i] = peak[i-1];
		}
	}

	ll maxLeft = -1;
	ll maxCount = -1;
	for(ll i=0;i<=n-k;i++){ 

		ll diff = peak[i+k-1] - peak[i];
		if(diff > maxCount && peak[i+1] > peak[i]){
			maxCount = diff;
			maxLeft = i+1;
		}
	}

	cout<<maxCount+1<<" "<<maxLeft<<endl;
}

int main(){

	ll t;
	cin>>t;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(t--){
		solve();
	}
}