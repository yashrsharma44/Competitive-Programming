#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int a,b;
	cin>>a>>b;
	// if(a == 0 || b == 0){
	// 	cout<<0<<endl;
	// 	return;
	// }
	int ans  = min({a,b,(a+b)/3});
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
