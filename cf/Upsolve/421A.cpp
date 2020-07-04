#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,a,b;
	cin>>n>>a>>b;
	vector<int> ans(n+1, 0);
	
	int aa = a;
	while(aa--){
		int vl;
		cin>>vl;
		if(ans[vl] == 0){
			ans[vl] = 1;
		}
	}

	while(b--){
		int vl;
		cin>>vl;
		if(ans[vl] == 0){
			ans[vl] = 2;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
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
