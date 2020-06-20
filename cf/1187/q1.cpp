#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n,s,t;
	cin>>n>>s>>t;

	int sum = (s+t);
	// if(sum == n){
	// 	cout<<n<<endl;
	// 	return;
	// }
	
	if(s >= n && t >= n){
		cout<<1<<endl;
		return;
	}

	int k = n - (n - s) - (n - t);
	int ans = max(s,t) - k  + 1;
	cout<<ans<<endl;


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
