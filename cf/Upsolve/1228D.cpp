#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> adj[n+1];
	ll mm = m;
	while(mm--){
		ll u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}