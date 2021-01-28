#include <bits/stdc++.h>
#define int long long 
int MOD = 1e9+7;
using namespace std;

int comb(int n, int r){

	if(r > n-r){
		r = n-r;
	}

	vector<int> C(r+1, 0);
	C[0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=min(i,r);j>0;j--){
			C[j] = (C[j] + C[j-1]) % MOD;
		}
	}

	return C[r];
}

void solve(){

	int n,k; cin>>n>>k;
	vector<int> a;
	int nn = n;

	map<int,int> cnt;
	while(nn--){
		int u; cin>>u;
		cnt[u]++;
		a.push_back(u);
	}

	sort(a.rbegin(), a.rend());
	map<int,int> fnd;
	for(int i=0;i<k;i++){
		fnd[a[i]]++;
	}

	int ans = 1;
	for(auto el : fnd){
		// cout<<el.first<<" "<<cnt[el.first]<<" "<<el.second<<endl;
		int val = comb(cnt[el.first], el.second);
		// cout<<val<<"-"<<endl;
		ans *= val;
		ans %= MOD;
	}

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

