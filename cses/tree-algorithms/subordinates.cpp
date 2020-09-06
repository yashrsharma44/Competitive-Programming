#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

vector<int> cnt(200005, 0);
vector<int> adj[200005];
// vector<bool> vis(200005, false);

int dfs(int node, int par = -1){

	int child = 0;
	for(auto ne : adj[node]){
		if(ne != par){
			child += dfs(ne, node);
		}
	}
	cnt[node] = child;
	return child + 1;
}

void solve(){

	int n;
	cin>>n;
	
	for(int i=2;i<=n;i++){
		int u; cin>>u;
		adj[i].push_back(u);
		adj[u].push_back(i);
	}

	int _ = dfs(1, -1);

	for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
	cout<<endl;

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
