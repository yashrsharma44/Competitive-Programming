#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int l,r,m;
	cin>>l>>r>>m;

	for(int i=l;i<=r;i++){

		int k = m % i;
		cout<<k<<endl;
		int n = m / i;
		if(n > 0 && k >= 0 && k <= (r-l)){
			cout<<i<<" "<<(l+k)<<" "<<l<<endl;
			return;
		}
	}

	cout<<l<<" "<<l<<" "<<(2*l-m)<<endl;

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
