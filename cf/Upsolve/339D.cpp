#include <bits/stdc++.h>
#define int long long 
#define MOD 1000000007
using namespace std;

class Node {
	int val;
	Node *left, *right;
	Node(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

void solve(){

	int n,m; cin>>n>>m;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}
	vector<vector<int>> q;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		q.push_back({u, v});
	}

	queue<Node*> q;
	for(int i=0;i<n;i++){

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
