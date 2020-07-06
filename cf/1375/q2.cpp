#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

	int n,m;
	cin>>n>>m;
	vector<vector<int> > g(n,vector<int>(m, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}	

	if(g[0][0] > 2 || g[0][m-1] > 2|| g[n-1][0] > 2|| g[n-1][m-1] > 2){
		cout<<"NO"<<endl;
		return;
	}	
	g[0][0] = g[0][m-1]= g[n-1][0] = g[n-1][m-1] = 2;

	for(int i=1;i<n-1;i++){
		if(g[i][0] > 3 || g[i][m-1] > 3){
			cout<<"NO"<<endl;
			return;
		}
		g[i][0] = g[i][m-1] = 3;
	}

	for(int i=1;i<m-1;i++){
		if(g[0][i] > 3 || g[n-1][i] > 3){
			cout<<"NO"<<endl;
			return;
		}
		g[0][i] = g[n-1][i] = 3;
	}

	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if(g[i][j] > 4){
				cout<<"NO"<<endl;
				return;
			}
			g[i][j] = 4;
		}
	}

	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
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
