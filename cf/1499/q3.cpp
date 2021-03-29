#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	vector<int> c(n);
	for(int i=0;i<n;i++) cin>>c[i];

	int ans = n * c[0] + n * c[1];
	
	int m1 = c[0], m2 = c[1];
	int u = c[0], v = c[1];
	int c1 = 1, c2 = 1;
	for(int i=2;i<n;i++){
		if(i%2 == 0){
			u += c[i];
			c1 += 1;
			m1 = min(m1, c[i]);
		} else {
			v += c[i];
			c2 += 1;
			m2 = min(m2, c[i]);
		}

		ans = min(ans, v + (n - c2) * m2 + u + (n - c1) * m1);
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