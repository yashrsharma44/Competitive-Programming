#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;
	vector< vector<string> >ans(n, vector<string>(m, "B"));
	ans[0][m-1] = "W";

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}