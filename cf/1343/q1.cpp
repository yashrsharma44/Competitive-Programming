#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	for(ll k=2;k<=n;k++){

		ll nm = (ll)pow(2, k) - 1;
		if(n % nm == 0){
			cout<<(n/nm)<<endl;
			return;
		}
	}

	return;

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
