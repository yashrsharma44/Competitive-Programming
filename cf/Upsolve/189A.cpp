#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

int memo[4005];

int a,b,c;

int dp(int i){
	// if(i == 0) return 1;
	if(i == 0) return 0;
	if(i < 0 || (i < a && i < b && i < c)) return INT_MIN;
		
	if(memo[i] != -1) return memo[i];

	memo[i] = 1 + max({dp(i-a), dp(i-b), dp(i-c)});
	return memo[i];
}

void solve(){

	for(int i=0;i<4005;i++) memo[i] = -1;

	int n; cin>>n>>a>>b>>c;
	int ans = dp(n);

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
