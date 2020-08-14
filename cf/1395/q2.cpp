#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n,m,sx,sy;
	cin>>n>>m>>sx>>sy;
	set<vector<int>> vis;

	vector<vector<int>> ans;
	ans.push_back(vector<int>({sx,sy}));
	ans.push_back(vector<int>({1, sy}));
	for(auto el : ans){
		vis.insert(el);
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(vis.count(vector<int>({i,j})) == 0){
					vis.insert(vector<int>({i,j}));
					ans.push_back(vector<int>({i,j}));
				} else {
					continue;
				}
			}
		} else {
			for(int j=m;j>=1;j--){
				if(vis.count(vector<int>({i,j})) == 0){
					vis.insert(vector<int>({i,j}));
					ans.push_back(vector<int>({i,j}));
				} else {
					continue;
				}	
			}
		}
	}

	for(auto el : ans){
		cout<<el[0]<<" "<<el[1]<<endl;
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
