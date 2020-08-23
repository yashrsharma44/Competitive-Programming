#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

int dfs(vector<int> &a, vector<int> &b, int i, int el){
	if(i >= a.size()) return 1;
	if(i == a.size()-1) {
		int lower = min(a[i], b[i]), upper = max(a[i], b[i]);
		if(el >= lower && el < upper) return 1;
		return 0;	
	}
	int lower = min(a[i], b[i]), upper = max(a[i], b[i]);
	
	if(el + 1 > upper) return 0;

	int L = max(el, lower);
	int R = upper;

	int ans = 0;
	for(int j=L;j<=R;j++){
		ans += dfs(a,b,i+1, j);
	}
	return ans;
}


void solve(){

	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i=0;i<n;i++) cin>>a[i];

	for(int i=0;i<n;i++) cin>>b[i];

	int ans = dfs(a, b, 0, min(a[0], b[0]));

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
