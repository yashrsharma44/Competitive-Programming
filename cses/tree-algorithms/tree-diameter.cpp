#include <bits/stdc++.h>
#define int long long 
using namespace std;
// #define MAX 1000005

vector<int> cnt(200005, 0);
vector<int> adj[200005];

int memo[200005];

int dfs(int node, int par=-1){

	int ans = 0;
	bool isLeaf = true;
	vector<int> cc;
	int bestChild = 0;
	for(auto child : adj[node]){
		if(child == par) continue;
		isLeaf = false;
		int val = dfs(child, node);
		bestChild = max(bestChild, val);
		cc.push_back(val);
	}
	if(isLeaf) return 0;

	sort(cc.begin(), cc.end(), greater<int>());
	ans = max(ans , 2 + cc[0] + cc[1]);
	for(int el : cc){
		ans = max(ans, el);
	}
	memo[node] = ans;
}

void solve(){

	int n; cin>>n;
	// adj.clear();
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans, memo[i]);
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
