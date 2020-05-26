#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(vector<ll> *adj, ll root, vector <ll> &elem, vector<bool> &visited){

	elem.push_back(root);
	for(ll neigh : adj[root]){

		if(!visited[neigh]){
			visited[neigh] = true;
			dfs(adj, neigh, elem, visited);
		}
	}


}

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> adj[n+1];
	ll mm =  m;
	while(mm--){
		ll u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// convert the components into a [low,high] interval

	vector<bool> visited(n+1, false);

	vector < vector<ll> > components;

	for(ll i=1;i<=n;i++){

		if(!visited[i]){
			vector<ll> elem;
			visited[i] = true;
			dfs(adj, i, elem, visited);
			components.push_back(elem);
		}
	}

	// map< vector<ll>, vector<ll> > mp;
	
	vector < vector<ll> > ranges;

	for(vector<ll> comp : components){

		vector<ll> range(2,0);
		range[0] = range[1] = comp[0];
		
		for(ll el : comp){
			range[0] = min(range[0], el);
			range[1] = max(range[1], el);
		}
		ranges.push_back(range);
		// mp[range] = comp;
	}

	// sort(ranges.begin(), ranges.end());
	ll count = 0;
	vector<ll> prevRange = ranges[0];
	for(ll i=1;i<ranges.size();i++){

		vector<ll> range = ranges[i];

		// [1,200] && [2,2]
		if(range[0] <= prevRange[1]){
			count++;
			prevRange[1] = max(range[1], prevRange[1]);
		} else {
			prevRange = range;
		}
	}


	cout<<count<<endl;
}

int main(){

	solve();

}