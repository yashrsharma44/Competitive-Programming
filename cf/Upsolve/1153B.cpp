#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int r,c,h;
	cin>>r>>c>>h;

	vector<int> col(c, 0), row(r, 0);
	for(int i=0;i<c;i++){
		cin>>col[i];
	}
	for(int i=0;i<r;i++){
		cin>>row[i];
	}
	vector<vector<int> > grid(r, vector<int>(c, 0));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(grid[i][j] == 1){
				cout<<min(row[i], col[j])<<" ";
			} else {
				cout<<0<<" ";
			}
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
