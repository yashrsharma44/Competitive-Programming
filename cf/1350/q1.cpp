#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	ll minFac = INT_MAX;
	for(ll i=2;i<=n;i++){
		if(n%i==0){
			minFac = i;
			break;
		}
	}

	ll ans=n+minFac;
	for(ll i=0;i<k-1;i++){
		ans+=2;
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
