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

	vector<ll> prefix(n, 0);
	prefix[0] = a[0];
	ll currMax = a[0];
	for(ll i=1;i<n;i++){
		currMax = max(currMax, a[i]);
		prefix[i] = max(prefix[i-1], currMax);
	}

	ll maxDiff = -1;
	for(ll i=0;i<n;i++){
		maxDiff = max(maxDiff, abs(prefix[i] - a[i]));
	}

	if(maxDiff == 0){
		cout<<0<<endl;
		return;
	}

	ll sum = 0;
	ll count = 0;
	for(ll i=0;i<64;i++){
		sum+=(ll)(pow(2,i));
		count+=1;
		if(sum >= maxDiff){
			break;
		}
	}

	cout<<count<<endl;
	

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}