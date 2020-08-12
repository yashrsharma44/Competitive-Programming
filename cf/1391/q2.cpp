#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){

	int n,m;
	cin>>n>>m;

	vector<vector<char>> a(n, vector<char>(m, 'a'));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	int count = 0;
	for(int i=0;i<n-1;i++){
		if(a[i][m-1] != 'D'){
			count++;
		}
	}

	for(int i=0;i<m-1;i++){
		if(a[n-1][i] != 'R'){
			count++;
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
