#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,d;
	cin>>n>>d;

	bool isPossible = false;

	if(d <= n){
		isPossible = true;
	}

	for(ll i=1;i<=n;i++){

		// cout<<i<<" "<<ceil((double)d / (i + 1))<<endl;

		ll val = i + ceil((double)d / (i + 1));

		if(val <= n){
			isPossible = true;
			break;
		}
	}

	if(isPossible){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){

	ll t;
	cin>>t;
	while(t--){
		solve();
	}

}