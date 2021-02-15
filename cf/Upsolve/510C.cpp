#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

bool comp(vector<int> &p1, vector<int> &p2){
	return p1[1] > p2[1];
}

int vis[100];
int mark;

void dfs(int node, set<int> *adj){

// Under process and we find it again
	if(vis[node] == 1){
		mark = 1;
		return;
	}

// visited node
	if(vis[node] == 2) return;
	vis[node] = 1;
	for(auto nei : adj[node]){
		dfs(nei, adj);
	}
	vis[node] = 2;
}

void solve(){

	int n; cin>>n;
	vector<string> words;
	for(int i=0;i<n;i++){
		string s; cin>>s;
		words.push_back(s);
	}

	// Alien Dictionary
	// Create a graph
	int N = 26;

	vector<int> indeg(N, 0);

	set<int> adj[N];
	for(int i=0;i<n-1;i++){
		int j=0;
		for(;j<min(words[i].length(), words[i+1].length());j++){
			if(words[i][j] != words[i+1][j]){
				adj[words[i][j] - 'a'].insert(words[i+1][j] - 'a');
				indeg[words[i+1][j] - 'a']++;
				break;
			}
		}

		if(j == words[i+1].length() && words[i].length() > words[i+1].length()){
			cout<<"Impossible"<<endl;
			return;
		}
	}

	// check if there is not backedge
	mark = 0;
	for(int i=0;i<100;i++) vis[i] = 0;

	for(int i=0;i<N;i++){
		if(adj[i].size() > 0)	
			dfs(i, adj);
	}

	if(mark == 1) {
		cout<<"Impossible"<<endl;
		return;
	}

	// topo sort
	queue<int> q;

	for(int i=0;i<N;i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}

	vector<int> ans;
	while(!q.empty()){

		auto el = q.front(); q.pop();
		ans.push_back(el);
		for(auto nei : adj[el]){
			--indeg[nei];
			if(indeg[nei] == 0){
				q.push(nei);
			}
		}
	}
	// cout<<ans.size()<<endl;
	// if(ans.size() != N){
	// 	cout<<"Impossible"<<endl;
	// 	return;
	// }

	for(auto el : ans)cout<<(char)(el + 'a');
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
