#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,k;
	cin>>n>>k;
	if(k == n || k == 0){
		cout<<0<<" "<<0<<endl;
		return;
	}
	if(k == n-1){
		cout<<1<<" "<<1<<endl;
		return;
	}

	int mn = 1;
	int mx = 0;
	if(k*3 <= n){
		mx= 2*k;
	} else {
		mx = n - k;
	}
	cout<<mn<<" "<<mx<<endl;

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
