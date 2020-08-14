#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

int dfs(vector<int> &a, vector<int> &b, int i){
	if(i == a.size()){
		return 0;		
	}
	int c = (a[i] & b[0]);
	for(int j=1;j<b.size();j++){
		c = min(c, (a[i]&b[j]));
	}
	return c | dfs(a,b,i+1);
}

void solve(){

	int n,m;
	cin>>n>>m;

	vector<int> a(n), b(m);
	for(int i=0;i<n;i++) cin>>a[i];

	for(int i=0;i<m;i++) cin>>b[i];

	int ans = 0;
	for(int i=0;i<n;i++){
		// int cc = a[i] ^ b[0];
		// int aa = b[0];
		// for(int j=1;j<m;j++){
		// 	if(cc < (a[i] ^ b[j])){
		// 		cc = a[i] ^ b[j];
		// 		aa = b[j];
		// 	}
		// }
		ans = ans | (a[i] & b[0]);
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
