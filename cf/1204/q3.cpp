#include <bits/stdc++.h>
#define int long long 

using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int> > &adj, int n){

	vector<vector<int> > ans(n, vector<int>(n, INT_MAX));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(adj[i][j] != 0){
				ans[i][j] = 1;
			}
			if(i == j){
				ans[i][j] = 0;
			}
		}
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}

	return ans;

}

void solve(){
	
	int n;
	cin>>n;

	vector<vector<int> > adj(n, vector<int>(n, 0));
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			adj[i][j] = s[j] - '0';
		}
	}

	int m;
	cin>>m;
	vector<int> path;
	while(m--){
		int vl;
		cin>>vl;
		path.push_back(vl-1);
	}

	vector<vector<int> >fw = floyd_warshall(adj, n);
	vector<int> ans;
	ans.push_back(0);
	m = path.size();
	for(int i=1;i<m;i++){
		int lastIdx = ans[ans.size()-1];
		int lastEl = path[lastIdx];
		if(fw[lastEl][path[i]] < i - lastIdx){
			ans.push_back(i-1);
		}
	}
	ans.push_back(m-1);
	cout<<ans.size()<<endl;
	for(int el : ans){
		cout<<path[el]+1<<" ";
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
