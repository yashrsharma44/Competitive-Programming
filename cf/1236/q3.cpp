#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector < vector<ll> > res(n, vector<ll>(n, 0));

	ll ctr=1;

	for(ll i=0;i<n;i++){
		
		if(i % 2 == 0){
			for(ll j=0;j<n;j++){
				res[i][j] = ctr++;
			}
		} else {
			for(ll j=n-1;j>=0;j--){
				res[i][j] = ctr++;
			}
		}
	}

	vector < vector<ll> > ans(n, vector<ll>(n, 0));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			ans[i][j] = res[j][i];
		}
	}

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
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