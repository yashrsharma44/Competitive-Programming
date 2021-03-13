#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n,k; cin>>n>>k;
	if(n%2==0){
		int ans = k % n;
		if(ans == 0) ans+=n;
		cout<<ans<<endl;
		return;
	}
	int hlf = (n+1) / 2;

	int lcm = (hlf * n) / __gcd(hlf, n);
	k = k % lcm;
	if(k == 0){
		cout<<1<<endl;
		return;
	}
	cout<<lcm<<" "<<k<<endl;
	int q = k / hlf;
	int off = k % n;
	if(off == 0) off+=n;

	off = off + q - 1;
	cout<<off<<endl; 
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
