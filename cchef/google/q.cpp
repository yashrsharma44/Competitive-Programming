#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void dfs(vector<int> *adj, int node, vector<bool> &vis, vector<int> anc, vector<int> &ans){

	for(int i=anc.size()-1;i>=0;i--){
		int el = anc[i];
		if(__gcd(el, node) == 1){
			ans[node] = el;
			break;
		}
	}

	for(auto ne : adj[node]){
		if(!vis[ne]){
			vis[ne] = true;
			anc.push_back(node);
			dfs(adj, ne, vis, anc, ans);
			anc.pop_back();
		}
	}

}

void solve(){

	int n;
	cin>>n;
	vector<int> values(n);
	for(int i=0;i<n;i++) cin>>values[i];

	vector<int> adj[n+1];
	
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n+1, false);
	vector<int> ans(n+1, -1);
	vis[1] = true;
	dfs(adj, 1, vis, vector<int>({1}), ans);

	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
