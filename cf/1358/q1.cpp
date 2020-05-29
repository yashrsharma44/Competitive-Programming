#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	if(n > m){
		swap(n,m);
	}		

	if(n % 2 == 0){
		ll ans = m * (n/2);
		cout<<ans<<endl;
	} else {
		ll ans = m * (n/2);
		ans += (m+1) / 2;
		cout<<ans<<endl;
	}

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
