#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n,k1,k2; cin>>n>>k1>>k2;
	int w,b; cin>>w>>b;
	vector<vector<int>> grid(n+1, vector<int>(2, 0));
	for(int i=k1+1;i<=n;i++){
		grid[i][0] = 1;
	}	
	for(int i=k2+1;i<=n;i++){
		grid[i][1] = 1;
	}

	for(int i=1;i<=n;i++){
		if(grid[i][0] == grid[i][1]){
			if(grid[i][0] == 0 && w > 0){
				w-=1;
				grid[i][0] = 2;
				grid[i][1] = 2;
			} else if(grid[i][0] == 1 && b > 0){
				b-=1;
				grid[i][0] = grid[i][1] = 2;
			}
		}
	}

	for(int i=2;i<=n;i++){
		if(grid[i][0] == grid[i-1][0]){
			if(grid[i][0] == 0 && w > 0){
				w-=1;
				grid[i][0] = grid[i-1][0] = 2;
			} else if(grid[i][0] == 1 && b > 0){
				b-=1;
				grid[i][0] = grid[i-1][0] = 2;
			}
		} 

		if(grid[i][1] == grid[i-1][1]){
				if(grid[i][1] == 0 && w > 0){
				w-=1;
				grid[i][1] = grid[i-1][1] = 2;
			} else if(grid[i][1] == 1 && b > 0){
				b-=1;
				grid[i][1] = grid[i-1][1] = 2;
			}
		}
	}

	if(w == 0 && b == 0){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;


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