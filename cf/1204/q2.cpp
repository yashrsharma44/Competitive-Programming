#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,l,r;
	cin>>n>>l>>r;

	int min = (n - l) + (1 << l)  - 1;
	int max = (1 << r) - 1 + ((n - r) * (1 << (r-1)));
	cout<<min<<" "<<max<<endl;

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
