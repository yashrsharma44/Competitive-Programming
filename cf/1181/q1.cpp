#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int x,y,z;
	cin>>x>>y>>z;

	int ans = (x+y) / z;
	int a1 = (x%z) + (y%z);
	if(a1 == 0){
		cout<<ans<<" "<<0<<endl;
		return;
	}

	if(a1 >= z){
		ans = x / z + y / z + 1;
		cout<<ans<<" "<<(z - max(x%z, y%z))<<endl;
		return;
	}

	cout<<(x / z + y / z)<<" "<<0<<endl;



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
