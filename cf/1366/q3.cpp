#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,m;
	cin>>n>>m;

	vector< vector<int> >vv(n, vector<int>(m, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int u;
			cin>>u;
			vv[i][j] = u;
		}
	}

	int count = 0;
	for(int i=0;i<n;i++){

		for(int j=0;j<(m/2);j++){
			if(vv[i][j] != vv[i][m - j - 1]){
				vv[i][j] = vv[i][m - j - 1];
				count+=1;
			}
		}
	}

	for(int j=0;j<m;j++){

		for(int i=0;i<(n/2);i++){
			if(vv[i][j] != vv[n - i - 1][j]){
				vv[i][j] = vv[n - i - 1][j];
				count+=1;
			}
		}
	}

	for(int i=0;i<n;i++){

		for(int j=0;j<(m/2);j++){
			if(vv[i][j] != vv[i][m - j - 1]){
				vv[i][j] = vv[i][m - j - 1];
				count+=1;
			}
		}
	}

	for(int j=0;j<m;j++){

		for(int i=0;i<(n/2);i++){
			if(vv[i][j] != vv[n - i - 1][j]){
				vv[i][j] = vv[n - i - 1][j];
				count+=1;
			}
		}
	}

	cout<<count<<endl;
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
