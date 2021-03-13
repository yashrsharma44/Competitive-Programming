#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void dfs(vector<int> a, map<int,int> &depth, int dp=0){
	if(a.size() == 0) return;
	int maxi = -1, max_ = -1;
	for(int i=0;i<a.size();i++){
		if(max_ < a[i]){
			max_ = a[i];
			maxi = i;
		}
	}

	depth[a[maxi]] = dp;
	vector<int> v1, v2;
	for(int i=0;i<maxi;i++){
		v1.push_back(a[i]);
	}
	for(int i=maxi+1;i<a.size();i++){
		v2.push_back(a[i]);
	}

	dfs(v1, depth, dp+1);
	dfs(v2, depth, dp+1);
}

void solve(){

	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	map<int,int> depth;
	dfs(a, depth);

	for(int el : a){
		cout<<depth[el]<<" ";
	}
	cout<<endl;
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