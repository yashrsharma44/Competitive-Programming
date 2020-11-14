#include <bits/stdc++.h>
// #define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n,m,k; cin>>n>>m>>k;
	vector<vector<int>> grid(n,vector<int>(m, -1));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	// vector<int> ans;
	vector<int> row(n, 0), col(m, 0);
	for(int i=0;i<n;i++) row[i] = i;
	for(int j=0;j<m;j++) col[j] = j;

	while(k--){
		char cc; int x, y;
		cin>>cc>>x>>y;
		x--;y--;

		if(cc == 'c'){
			swap(col[x], col[y]);
		} else if(cc == 'r'){
			swap(row[x], row[y]);
		} else {	
			x = row[x];
			y = col[y];
			cout<<grid[x][y]<<endl;
		}
	}

	// for(int el : ans) cout<<el<<endl;

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
