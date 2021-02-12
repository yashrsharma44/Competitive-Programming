#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

int dp[5005][5005];

int dfs(vector<int> &pre, int i, int m, int k){
    int n = pre.size();
    if(i == n+1) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    int ans = 0;
    if(i+m < n && k > 0){
        ans = pre[i+m] - pre[i] + dfs(pre, i+m, m, k-1);
        ans = max(ans, dfs(pre, i+1, m, k));    
    }
    return dp[i][k] = ans;
}
// 0 1 3 6 10 15
// 0 1 2 3  4  5
void solve(){
    
    int n,m,k; cin>>n>>m>>k;
    vector<int> a;
    int nn = n;
    while(nn--){
        int u; cin>>u;
        a.push_back(u);
    }

    for(int i=0;i<5005;i++){
        for(int j=0;j<5005;j++){
            dp[i][j] = -1;
        }
    }

    vector<int> pre;
    pre.push_back(0);
    for(auto el : a){
        pre.push_back(pre.back() + el);
    }

    int ans = dfs(pre, 0, m, k);
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
