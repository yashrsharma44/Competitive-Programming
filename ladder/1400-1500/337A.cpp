#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n,m; cin>>n>>m;
	vector<int> arr(m);
	for(int i=0;i<m;i++) cin>>arr[i];

	sort(arr.begin(), arr.end());
	int ans = INT_MAX;
	for(int i=n-1;i<m;i++){
		ans = min(ans, arr[i] - arr[i-(n-1)]);
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
