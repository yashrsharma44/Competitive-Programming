#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int x,y,n;
	cin>>x>>y>>n;

	// int ans = x + y;
	// while(ans <= n){
	// 	ans += x;
	// }
	// if(ans > n){
	// 	ans -= x;
	// }
	// cout<<ans<<endl;
	int ans = 0;
	int z = (n - y)/x;
	// cout<<"z"<<z<<endl;
	ans = (z * x )+ y;
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
