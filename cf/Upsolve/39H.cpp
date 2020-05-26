#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll convertRadix(ll num, ll k){

	vector<ll> n;
	while(n>0){
		n.push_back(num%10);
		n/=10;
	}

	ll ans = 0;
	for(ll i=0;i<n.size();i++){
		ans += (pow(k,i) * n[i]);
	}

	return ans;
}

void solve(){

	ll k;

	vector< vector<ll> >(k+1);


}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}