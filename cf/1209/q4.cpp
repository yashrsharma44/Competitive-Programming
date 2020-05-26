#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void dfs(vector<ll> *adj, ll root, vector<bool> &visited){

	visited[root] = true;

	for(ll neigh : adj[root]){
		if(!visited[neigh]){
			// visited[neigh] = true;
			dfs(adj, neigh, visited);
		}
	}
}

void solve(){

	ll n,k;
	cin>>n>>k;

	ll m = k;

	vector<ll> adj[n+1];
	while(k--){
		ll u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Count the no. of components
	ll comp = 0;
	vector<bool> visited(n, false);

	for(ll i=1;i<=n;i++){
		if(!visited[i]){
			visited[i] = true;
			dfs(adj, i, visited);
			comp++;
		}
	}
	// cout<<comp<<endl;

	cout<<(m - (n - comp))<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}
}