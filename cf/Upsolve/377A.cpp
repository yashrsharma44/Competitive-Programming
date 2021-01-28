#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};

void dfs(vector<string> &grid, vector<vector<bool>> &vis, int i, int j, int &ss){

	for(int k=0;k<4;k++){
		int rr = i + dr[k];
		int cc = j + dc[k];

		if(rr>=0&&rr<grid.size() && cc>=0&&cc<grid[0].size() && grid[rr][cc] == '.' && !vis[rr][cc]){
			vis[rr][cc] = true;
			if(ss <= 0){
				grid[rr][cc] = 'X';
			}
			ss--;
			dfs(grid, vis, rr, cc, ss);
		}
	}

}


void solve(){

	int n,m,k; cin>>n>>m>>k;
	vector<string> grid;
	int nn = n;
	while(nn--){
		string s; cin>>s;
		grid.push_back(s);
	}

	int comp = 0;
	vector< vector<bool> > vis(n, vector<bool>(m, false));
	int rr,cc;
	int s=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == '.' ){
				rr = i; cc = j;
				s++;
			}
		}
	}

	vis[rr][cc] = true;
	int val = s-k;
	val--;
	dfs(grid, vis, rr, cc, val);

	for(auto el : grid){
		for(auto e : el){
			cout<<e;
		}
		cout<<endl;
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
