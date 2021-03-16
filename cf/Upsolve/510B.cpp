#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

bool dfs(int r, int c, vector<string> &grid, int k, char el, vector<vector<bool>> &vis, int px=-1, int py=-1){
	
	int dr[4] = {-1,0,1,0};
	int dc[4] = {0,1,0,-1};

	int N = grid.size(), M = grid[0].size();

	for(int z=0;z<4;z++){
		int rr = r + dr[z]; int cc = c + dc[z];
		if(rr>=0 && rr<N && cc>=0 && cc < M && grid[rr][cc] == el){
			if(!vis[rr][cc]){
				vis[rr][cc] = true;
				if(dfs(rr,cc,grid,k+1, el, vis, r, c)) return true;
			} else {
				if(px!=rr && py!=cc && k+1 >= 4) return true;
			}
		}
	}
	return false;
}

void solve(){

	int n,m; cin>>n>>m;
	vector<string> grid(n);
	for(int i=0;i<n;i++){
		cin>>grid[i];
	}

	// For every character, find if there is a cycle of length >= 4
	bool isPos = false;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vector<vector<bool>> vis(n, vector<bool>(m, false));
			vis[i][j] = true;
			if(dfs(i, j, grid, 0, grid[i][j], vis)){
				isPos = true;
				break;
			}
		}
	}

	if(isPos){
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
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
