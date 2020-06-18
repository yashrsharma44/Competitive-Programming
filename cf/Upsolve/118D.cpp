#include <bits/stdc++.h>
#define int long long 
#define MOD 1000000007
using namespace std;

void solve(){

	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;

	vector<int> dp(n1+n2+1, 0);

	dp[1] = (k1 > 1 || k2 > 1) ? 1 : 0;
	for(int i=1;i<=n1+n2;i++){

		if(i >= k1){
			dp[i] += dp[i - k1];
		}
		if(i >= k2){
			dp[i] += dp[i - k2];
		}

	}
	cout<<dp[n1+n2]<<endl;

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
