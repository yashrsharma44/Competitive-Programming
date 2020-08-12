#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005



void solve(){

	int MOD = 1e9+7;

	int n;
	cin>>n;

	vector<int> dp(MAX, 0);

	vector<int> fact(MAX, 1);
	for(int i=1;i<MAX;i++){
		fact[i] = (fact[i-1] * i) % MOD;
		fact[i] %= MOD;
	}


	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 0;

	dp[3] = 1;

	for(int i=4;i<=n;i++){
		int z = i - 2;
		dp[i] = dp[i-1] + ((fact[z] * ((z)*(z+1) / 2)) % MOD);
		dp[i] %= MOD;
	}

	int ans = (n*dp[n]) % MOD;
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
