#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	map<vector<int>, int> mp;

	int nn = n;
	while(nn--){
		int u, v; cin>>u>>v;
		mp[{u, v}] += 1;
	}

	int max_ = 0;
	for(auto entry : mp){
		max_ = max(max_, entry.second);
	}

	cout<<max_<<endl;




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
