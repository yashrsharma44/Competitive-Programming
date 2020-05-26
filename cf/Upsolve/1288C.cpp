#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;

ll comb(ll n, ll k){

	vector< vector<ll> > C(n+1, vector<ll>(k+1, 0));

	for(ll i=0;i<=n;i++){

		for(ll j=0;j<=min(i,k);j++){

			// Base case
			if(j == 0 || j == i){
				C[i][j] = 1;
			} else {
				C[i][j] = (((C[i-1][j-1] + C[i-1][j]) % MOD) + MOD) % MOD;
			}
		}
	}

	return ((C[n][k] % MOD) + MOD) % MOD;

}

void solve(){

	ll n,m;
	cin>>n>>m;

	cout<<comb((n+2*m-1), (2*m))<<endl;

}

int main(){

	solve();

}