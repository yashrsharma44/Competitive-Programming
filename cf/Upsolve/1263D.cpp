#include <bits/stdc++.h>
#define ll int

using namespace std;

void dfs(ll root, vector<ll> *adj, vector<bool> &visited){

	for(auto neigh : adj[root]){
		if(!visited[neigh]){
			visited[neigh] = true;
			dfs(neigh, adj, visited);
		}
	}

}

void solve(){

	ll n;
	cin>>n;

	vector<string> a;
	ll nn = n;
	while(nn--){
		string s;
		cin>>s;
		a.push_back(s);
	}

	vector<ll> adj[n+26];

	for(ll i=0;i<n;i++){
		for(char c : a[i]){
			adj[i].push_back(n+c-'a');
			adj[n+c-'a'].push_back(i);
		}
	}


	ll count=0;
	vector<bool> visited(n+26,false);
	for(ll i=n;i<n+26;i++){

		if(!visited[i] && adj[i].size() != 0){
			visited[i] = true;
			dfs(i, adj, visited);
			count+=1;
		}

	}

	cout<<count<<endl;



}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}

}