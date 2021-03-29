#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n,m; cin>>n>>m;
	vector<int> col(n);
	for(int i=0;i<n;i++) cin>>col[i];

	map<int, set<int>> adj;
	for(auto cl : col){
		adj[cl] = set<int>();
	}
	
	for(int i=0;i<m;i++){
		int u, v; cin>>u>>v;
		u-=1; v-=1;
		if(col[u] != col[v]){
			adj[col[u]].insert(col[v]);
			adj[col[v]].insert(col[u]);			
		}
	}

	int mx = 0;
	int ans = INT_MAX;
	for(auto el : adj){
		mx = max(mx, (int)(el.second.size()));
	}

	for(auto el : adj){
		if((int)(el.second.size()) == mx){
			ans = min(ans, el.first);
		}
	}

	cout<<ans<<endl;
	
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