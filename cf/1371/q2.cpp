#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,r;
	cin>>n>>r;

	if(n <= r){
		int ans = (((n)*(n-1)) / 2) + 1;
		cout<<ans<<endl;
	} else {
		int ans = ((r)*(r+1))/2;
		cout<<ans<<endl;
	}


	
	// cout<<sum<<endl;

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
