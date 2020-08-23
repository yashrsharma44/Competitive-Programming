#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005
int k;
int n;
vector<vector<int>> adj(7, vector<int>(7, 0));
vector<int> color(7, 0);
vector<int> dfs(int start, int end, int blue, int red){
	if(start == end){
		return vector<int>({0, 1 - color[start], color[start]});
	}

	int ans = MAX;
	for(int i=1;i<=n;i++){
		int ne = i;
		if(adj[start][ne] != 0){
			auto val = dfs(ne, end, 1 - color[start] + blue, color[start] + red);
			if(abs(val[1] - val[2]) <= k) ans = min(ans, adj[start][ne] + val[0]);
		}	
	}

	return vector<int>({ans, 1 - color[start] + blue, color[start] + red});
}


void solve(){

	int m;
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++){
		int u,v,l;
		cin>>u>>v>>l;
		adj[u][v] = l;
		// adj[v][u] = l;
	}

	
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}

	auto dist = dfs(1, n, 0, 0);
	cout<<dist[0]<<endl;
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
