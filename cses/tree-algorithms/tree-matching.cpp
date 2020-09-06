#include <bits/stdc++.h>
#define int long long 
using namespace std;
// #define MAX 1000005

vector<int> cnt(200005, 0);
vector<int> adj[200005];

int memo[200005][2];

void dfs(int node, int par=-1){

	// if(memo[node][choice] != -1) return memo[node][choice];
	memo[node][0] = memo[node][1] = 0;
	// we have 2 choices that we can make for a given node
	// we make an edge between node - child(one).
	// we can skip making an edge and take the sum of the childs
	// max values
	

	vector<int> childValues;
	bool isLeaf = true;
	int childCount = 0;
	// skip all edge from node to child
	for(auto child : adj[node]){
		if(child != par){
			isLeaf = false;
			childCount ++; 
			dfs(child, node);
		}
	}
	
	if(isLeaf) return;
	for(auto child : adj[node]){
		if(child != par){
			childValues.push_back(max(memo[child][0], memo[child][1]));
		}
	}

	vector<int> pre(childValues), suf(childValues);

	for(int i=1;i<childCount;i++){
		pre[i] += pre[i-1];
	}
	for(int i=childCount-2;i>=0;i--){
		suf[i] += suf[i+1];
	}

	memo[node][0] = suf[0];
	int k = 0;
	// try to make an edge between node and one child
	for(auto child : adj[node]){

		if(child == par) continue;
		int sum1 = (k == 0) ? 0 : pre[k-1];
		int sum2 = (k == (pre.size()) - 1) ? 0 : suf[k+1];

		memo[node][1] = max(memo[node][1], 1 + sum1 + sum2 + memo[child][0]);

		// if(k == 0){
		// 	int sum1 = 0, sum2 = suf[k+1];
		// 	memo[node][1] = max(memo[node][1], 1 + sum1 + memo[child][0] + sum2);
		// } else if(k == (int)(pre.size())-1){
		// 	int sum1 = pre[k-1], sum2 = 0;
		// 	memo[node][1] = max(memo[node][1], 1 + sum1 + memo[child][0] + sum2);
		// } else {
		// 	int sum1 = pre[k-1], sum2 = suf[k+1];
		// 	memo[node][1] = max(memo[node][1], 1 + sum1 + memo[child][0] + sum2);
		// }
		k++;
	}
	
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

	for(int i=0;i<200005;i++){
		for(int j=0;j<2;j++){
			memo[i][j] = -1;
		}
	}
	dfs(1, 0);
	int ans = max(memo[1][0], memo[1][1]);
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
