#include <bits/stdc++.h>
#define int long long 

using namespace std;

void dfs(int node, vector<int> *adj, vector< pair<int,int> > &ans, vector<bool> &visited, int &root){

	for(auto n : adj[node]){
		if(!visited[n]){
			visited[n] = true;
			ans.push_back({root, n});
			dfs(n, adj, ans, visited, n);
		}
	}

}

class cmp {
	vector<int> deg;
public:
	cmp(vector<int> &deg){
		this->deg = deg;
	}

	bool operator()(int n1, int n2){
		return this->deg[n1] > this->deg[n2];
	}
};

void solve(){

	int n,m;
	cin>>n>>m;

	vector<int> adj[n+1];
	vector<int> deg(n+1, 0);
	while(m--){
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int maxDeg = -1;
	int maxNode = -1;
	for(int i=1;i<=n;i++){
		if(maxDeg < deg[i]){
			maxDeg = deg[i];
			maxNode = i;
		}
	}

	vector< pair<int,int> > ans;
	vector<bool> visited(n+1, false);

	// for(int i=1;i<=n;i++){
	// 	sort(adj[i].begin(), adj[i].end(), cmp(deg));
	// }

	queue<int> q;
	q.push(maxNode);
	visited[maxNode] = true;
	while(!q.empty()){

		int sz = q.size();
		for(int i=0;i<sz;i++){

			int el = q.front();
			q.pop();

			for(auto n : adj[el]){
				if(!visited[n]){
					visited[n] = true;
					q.push(n);
					ans.push_back({el, n});
				}
			}

		}

	}

	for(auto el : ans){
		cout<<el.first<<" "<<el.second<<endl;
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
