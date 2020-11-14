#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005


void solve(){

	int x,y,a,b;
	cin>>x>>y>>a>>b;

	vector<vector<int>> ans;
	for(int i=a;i<=x;i++){
		for(int j=b;j<=y;j++){
			if(i > j) ans.push_back({i, j});
		}
	}

	a = ans.size();
	if(a == 0){
		cout<<0<<endl;
		return;
	}
	cout<<a<<endl;
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
