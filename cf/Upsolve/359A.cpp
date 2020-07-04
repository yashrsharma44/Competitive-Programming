#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,m;
	cin>>n>>m;
	int ans = 4;
	vector<vector<int> >arr(n, vector<int>(m, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int v;
			cin>>v;
			if(v == 1 && (i == 0 || i == n-1 || j == 0 || j == m-1)){
				ans = 2;
			}
		}
	}

	cout<<ans<<endl;
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
