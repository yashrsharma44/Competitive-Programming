#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int a,b,k; cin>>a>>b>>k;
	vector<int> aa,bb;
	int nn = k;
		
	vector<int> ain(a+1, 0), bin(b+1,0);

	while(nn--){
		int u; cin>>u;
		aa.push_back(u);
		ain[u]++;
	}

	nn = k;
	while(nn--){
		int u; cin>>u;
		bb.push_back(u);
		bin[u]++;
	}

	int ans = 0;
	for(int i=0;i<k;i++){
		ans += k - (ain[aa[i]] + bin[bb[i]] - 1);
	}
	ans /= 2;
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

