#include <bits/stdc++.h>

#define int long long 
#define N 100007
using namespace std;
int a[N], g[N];
int dfs(vector<int> *adj, vector<bool> &vis, int node, vector<int> &people, vector<int> &hindex, bool &isPos){

	a[node] = people[node];
	int childG = 0;
	for(auto child : adj[node]){
		if(!vis[child]){
			vis[child] = true;
			a[node] += dfs(adj, vis, child, people, hindex, isPos);
			childG += g[child];
		}
	}

	g[node] = (a[node] + hindex[node]) / 2;
	// if((a[node] + hindex[node]) < 0) isPos = false;
	// if (hindex[node] < -people[node] || hindex[node] > people[node]) isPos = false;
	if((a[node] + hindex[node]) & 1) isPos = false;
	if(g[node] < 0 || g[node] > a[node]) isPos = false;
	if(childG > g[node]) isPos = false;

	return a[node];
}

void solve(){

	// Lets do a city wise check
	// h-index is the total good - total bad mood people
	// We have computed the h-index city wise
	// Lets do a city wise computation of the good mood
	// people and total people
	// We have g[v] - b[v] = h[v], h[v] the hindex 
	// ....... g[v] + b[v] = a[v], a[v]-total people in the parent and child
	// solving.. g[v] = (a[v] + h[v]) / 2;
	// Since g[v] is a positive integer,
	// we have 3 conditions - 
	// 1. (a[v] + h[v]) is even
	// 2. g[v] >= 0 && g[v] <= a[v];
	// 3. sum(g[childs of v]) <= g[v]

	int n,m;
	cin>>n>>m;
	vector<int> people(n+1), hindex(n+1);
	for(int i=0;i<n;i++){
		cin>>people[i+1];
	}
	for(int i=0;i<n;i++){
		cin>>hindex[i+1];
	}
	vector<int> adj[n+1];
	int kk = n-1;
	while(kk--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		// Error :P
		// for a tree, we should also consider the reverse edge :P
		adj[v].push_back(u);
	}
	vector<bool> vis(n+1, false);
	vis[1] = true;
	bool isPos = true;
	auto count = dfs(adj, vis, 1, people, hindex, isPos);

	if(isPos){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;

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
