#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> fact(n+10,1);
	fact[0] = 1;

	for(ll i=1;i<n+10;i++){
		fact[i] = (fact[i-1] * i) % m;
	}

	ll happy = 0;
	for(ll i=1;i<=n;i++){

		happy += ((n - i + 1) * ((fact[i] * fact[n - i + 1]) % m)%m);
	}

	cout<<(happy%m)<<endl;

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
