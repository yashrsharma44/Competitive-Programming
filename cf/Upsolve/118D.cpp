#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

int memo[105][105][12][12];

int dp(int n1, int n2, int &k1, int &k2, int p1, int p2){
	if(n1 == 0 && n2 == 0){
		return 1;
	}

	if(memo[n1][n2][p1][p2] != -1) return memo[n1][n2][p1][p2];
	int ans = 0;
	if(n1 > 0 && p1 > 0){
		ans += dp(n1-1, n2, k1, k2, p1-1, k2);
		ans %= MOD;
	}

	if(n2 > 0 && p2 > 0){
		ans += dp(n1, n2-1, k1,k2, k1, p2-1);
		ans %= MOD;
	}

	return memo[n1][n2][p1][p2] = ans;
}

void solve(){

	for(int i=0;i<105;i++){
		for(int j=0;j<105;j++){
			for(int k=0;k<12;k++){
				for(int l=0;l<12;l++){
					memo[i][j][k][l] = -1;
				}
			}
		}
	}

	int n1, n2, k1, k2; cin>>n1>>n2>>k1>>k2;

	int ans = dp(n1, n2, k1, k2, k1, k2);
	ans = ans % MOD;
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
