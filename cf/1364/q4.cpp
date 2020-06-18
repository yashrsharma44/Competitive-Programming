#include <bits/stdc++.h>
#define int long long

using namespace std;

void dfs(vector<int> *adj, int root, vector<bool> &visited, vector<int> &comp){

	for(auto neigh : adj[root]){
		if(!visited[neigh]){

			visited[neigh] = true;
			comp.push_back(neigh);
			dfs(adj, neigh, visited, comp);

		}
	}

}

void cycle(vector<int> *adj, int u, int p, vector<int> &color, vector<int> &mark, vector<int> &par, int &cycleNumber){

	if(color[u] == 2){
		return;
	}

	if(color[u] == 1){

		cycleNumber+=1;
		int cur = p;
		mark[cur] = cycleNumber;

		while(cur != u){
			cur = par[cur];
			mark[cur] = cycleNumber;
		}
		return;
	}

	par[u] = p;

	color[u] = 1;

	for(auto neigh : adj[u]){
		if(neigh == par[u]){
			continue;
		}
		cycle(adj, neigh, u, color, mark, par, cycleNumber);
	}

	color[u] = 2;
}

void loadCycle(int n, vector<int> &mark, int cycleNumber, vector<int> *cycles){

	for(int i=1;i<=n;i++){
		if(mark[i] != 0){
			cycles[mark[i]].push_back(i);
		}
	}

}
	
void solve(){

	int n,m,k;
	cin>>n>>m>>k;

	vector<int> adj[n+1];
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Connected Components;
	vector< vector<int> >comps;
	vector<bool> visited(n+1, false);

	for(int i=1;i<=n;i++){

		if(!visited[i]){

			visited[i] = true;
			vector<int> comp;
			comp.push_back(i);

			dfs(adj, i, visited, comp);
			if(comp.size() > 0)
				comps.push_back(comp);
		}

	}

	if(comps.size() >= (k + 1)/2){
		cout<<1<<endl;
		for(int i=0;i<comps.size();i++){
			cout<<comps[i][0]<<" ";
		}
		cout<<endl;
		return;
	}

	vector<int> color(n+1, 0), par(n+1, -1), mark(n+1, 0);
	int cycleNumber = 0;
	cycle(adj, 1, 0, color, mark, par, cycleNumber);

	vector<int> cycles[n+1];

	int choice = -1;
	for(int i=1;i<=cycleNumber;i++){
		if(cycles[i].size() <= k){
			choice = i;
			break;
		}
	}
	cout<<2<<endl;
	cout<<cycles[choice].size()<<endl;
	for(auto el : cycles[choice]){
		cout<<el<<" ";
	}
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
