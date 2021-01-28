#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

bool dfs(map<vector<int>, vector<vector<int>> > &adj, 	map<int, vector<int>> &mp, set<vector<int>> &vis, vector<int> node, vector<int> &res){

	if(node == res) return true;
	for(auto nei : adj[node]){
		
		if(vis.count(nei) == 0) {
			vis.insert(nei);
			if(dfs(adj, mp, vis, nei, res)) return true;
		}
	}
	return false;
}


void solve(){

	int n; cin>>n;
	map<int, vector<int>> mp;
	map<vector<int>, vector<vector<int>> > adj;
	int it = 1;
	for(int i=0;i<n;i++){
		int u,v,w; cin>>u>>v>>w;
		if(u == 1){
			mp[it++] = {v,w};
			adj[{v,w}] = vector<vector<int>>();
			for(auto el : mp){
				auto node = el.second;
				if(v > node[0] && v < node[1] || w > node[0] && w < node[1]){
					adj[{v,w}].push_back(node);
				}
				if(node[0] > v && node[0] < w || node[1] > v && node[1] < w){
					adj[node].push_back({v,w});
				}
			}
		} else {
			set<vector<int>> vis;
			vis.insert(mp[v]);
			if(dfs(adj, mp, vis, mp[v], mp[w])){
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}

		}
	}



}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
