#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n,q; cin>>n>>q;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	vector<vector<int>> qq;
	for(int i=0;i<q;i++){
		int u,v; cin>>u>>v;
		qq.push_back({u,v});
	}

	vector<int> sum(n+2, 0);
	for(auto qu : qq){
		sum[qu[0]] += 1;
		sum[qu[1]+1] -= 1;
	}

	for(int i=1;i<n+2;i++){
		sum[i] += sum[i-1];
	}

	int ans = 0;
	sort(sum.rbegin(), sum.rend());
	sort(a.rbegin(), a.rend());

	// for(auto el : sum) cout<<el<<" ";
	// cout<<endl;
	for(int i=0;i<n;i++){
		// cout<<sum[n - i]<<" "<<a[n-i]<<endl;
		ans += sum[i] * a[i];
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
