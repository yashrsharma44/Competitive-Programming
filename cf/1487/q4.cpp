#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	int ans = 0;
	for(int i=1;i<=100000LL;i++){
		int a2 = i*i + 1LL;

		if(a2 >= 1 && a2 % 2 == 0){
			int c = a2 / 2;
			if(c <= n && c >= 2) ans++;
		}
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