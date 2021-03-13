#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){
	int n; cin>>n;
	vector<int> a, b;
	int nn = n;
	while(nn--){
		int u,v; cin>>u>>v;
		a.push_back(u);
		b.push_back(v);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(n % 2 == 0){
		int l1 = a[n/2-1], l2 = a[n/2];
		int r1 = b[n/2-1], r2 = b[n/2];

		int ans = (l2 - l1 + 1) * (r2 - r1 + 1);
		cout<<ans<<endl;
		return;
	}

	cout<<1<<endl;
	
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
