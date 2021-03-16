#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	vector<int> pos(n);
	for(int i=0;i<n;i++){
		pos[i] = min(i+1, a[i]);
	}

	vector<int> ans(n);
	int max_ = 0;
	for(int i=n-1;i>=0;i--){
		max_ = max(max_, pos[i]);
		if(max_ > 0){
			ans[i] = 1;
			max_ -= 1;
		}
	}

	for(auto el : ans) cout<<el<<" ";
	cout<<endl;
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