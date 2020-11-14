#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

bool check(string &grid, vector<int> &maxCol){
	for(int el : maxCol){
		for(int i=0;i<grid.length();i++){
			if(grid[i] - '0' == el) return true;
		}
	}
	return false;
}

void solve(){

	int n,m; cin>>n>>m;
	vector<string> grid(n);
	for(int i=0;i<n;i++) cin>>grid[i];

	vector<int> maxCol(m, 0);
	for(int c=0;c<m;c++){

		for(int r=0;r<n;r++){
			maxCol[c] = max(maxCol[c], (int)(grid[r][c] - '0'));
		}
	}
	set<int> ans;
	for(int c=0;c<m;c++){
		for(int r=0;r<n;r++){
			if(grid[r][c] - '0' == maxCol[c]) ans.insert(r);
		}
	}

	int aa = ans.size();
	cout<<aa<<endl;

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
