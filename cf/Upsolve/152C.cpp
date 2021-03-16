#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n,m; cin>>n>>m;
	vector<string> names(n);

	for(int i=0;i<n;i++){
		cin>>names[i];
	}

	int ans = 1;
	int MOD = 1e9 + 7;
	for(int c=0;c<m;c++){
		set<char> elems;
		for(int r=0;r<n;r++){
			elems.insert(names[r][c]);
		}
		// if(elems.size() == 1) continue;
		ans *= elems.size();
		ans %= MOD;
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
