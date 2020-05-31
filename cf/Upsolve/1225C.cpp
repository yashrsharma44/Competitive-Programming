#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,p;
	cin>>n>>p;

	for(ll i=1;i<=1000;i++){

		ll ans = n - (i * p);
		if(ans <= 0 || ans < i){
			cout<<-1<<endl;
			return;
		}

		if(__builtin_popcountll(ans) <= i){
			cout<<i<<endl;
			return;
		}

	}

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}