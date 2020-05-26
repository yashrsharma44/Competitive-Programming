#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;

	vector < vector<ll> > arr(n, vector<ll>(n, 0));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			ll vl;
			cin>>vl;
			arr[i][j]= vl;
		}
	}

	vector<ll> res(n,0);
	
	// Fill the code :P
	for(ll i=0;i<=n-3;i++){
		res[i] = sqrt((arr[i][i+1] * arr[i][i+2]) / (arr[i+1][i+2]));
	}

	res[n-2] = arr[n-2][0] / res[0];
	res[n-1] = arr[n-1][0] / res[0];

	for(ll el : res){
		cout<<el<<" ";
	}
	cout<<endl;

}

int main(){
	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}