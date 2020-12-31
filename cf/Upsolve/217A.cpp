#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void dfs(map<vector<int>, vector<vector<int>> > &adj, set<vector<int>> &vis, vector<int> node){

	for(auto neigh : adj[node]){
		if(vis.count(neigh) == 0){
			vis.insert(neigh);
			dfs(adj, vis, neigh);
		}
	}

}

void solve(){

	int n;
	cin>>n;

	vector<vector<int>> coords;
	int nn = n;
	while(nn--){
		int u, v;
		cin>>u>>v;
		coords.push_back({u, v});
	}

	map<vector<int>, vector<vector<int>> > adj;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){

			if(coords[i][0] == coords[j][0] || coords[i][1] == coords[j][1]){
				adj[coords[i]].push_back(coords[j]);
				adj[coords[j]].push_back(coords[i]);				
			}

		}
	}

	int comp = 0;
	set<vector<int>> vis;

	for(int i=0;i<n;i++){

		if(vis.count(coords[i]) == 0){

			vis.insert(coords[i]);
			dfs(adj, vis, coords[i]);
			comp++;
		}

	}

	cout<<(comp-1)<<endl;


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
