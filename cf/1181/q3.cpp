#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

bool diff(vector<vector<char>> &grid, int i, int j){
	return (grid[i][j] != grid[i+1][j] && grid[i+1][j] != grid[i+2][j]);
}

bool same(vector<vector<char>> &grid, int i, int j, int k){
	return (grid[i][j] == grid[i][k] && grid[i+1][j] == grid[i+1][k] && grid[i+2][j] == grid[i+2][k]);
}

void solve(){

	int n,m; cin>>n>>m;
	vector<vector<char>> grid(n, vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}

	int count = 0;
	for(int i=0;i<=n-3;i++){
		int local = 0;
		if(diff(grid, i, 0)) count++, local++;
		for(int j=1;j<m;j++){
			if(diff(grid, i, j) && same(grid, i, j, j-1)){
				local++;
			} else {
				if(diff(grid, i, j)){
					local = 1;
				} else {
					local = 0;
				} 
			}
			count+=local;	

		}
	}

	cout<<count<<endl;


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
