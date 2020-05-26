#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll x,n,m;
	cin>>x>>n>>m;

	for(ll i=0;i<n;i++){

		if(x <= 20){
			break;
		}
		x = x / 2 + 10;
	}

	ll val = m * 10;
	if(val >= x){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll t;
	cin>>t;
	// t=1;
	while(t--){
		solve();
	}
}