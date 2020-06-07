#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){

	ll n;
	cin>>n;

	ll ans = 0;
	for(ll i=0;i<60;i++){

		if((1LL<<i) & n){
			ans += (1LL<<(i+1)) - 1;
		}
	}

	cout<<ans<<endl;
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
