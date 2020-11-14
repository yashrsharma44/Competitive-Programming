#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void shift(vector<string> &grid, int i){
	string s = grid[i];
	char last = s.back();
	s = last + s.substr(0, 7);
	grid[i] = s;
}

bool check(vector<string> &grid){
	for(int i=1;i<8;i++){
		if(grid[i][0] == grid[i-1][0] || grid[i].back() == grid[i-1].back()) return false;
	}
	return true;
}

void solve(){

	int n = 8;
	vector<string> grid(n);
	for(int i=0;i<n;i++) cin>>grid[i];

	vector<string> a({"WBWBWBWB", "BWBWBWBW"});
	for(auto el : grid){
		if(a[0] == el || a[1] == el) continue;
		else {
			cout<<"NO"<<endl;
			return;
		}
	}	
	cout<<"YES"<<endl;
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
