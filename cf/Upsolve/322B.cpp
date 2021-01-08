#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int a,b,c; cin>>a>>b>>c;
	if(a == 0 || b == 0 || c == 0){
		cout<<(a/3+b/3+c/3)<<endl;
		return;
	}
	int ans = max({a/3+b/3+c/3, 1 + (a-1)/3 + (b-1)/3 + (c-1)/3, 2 + (a-2)/3 + (b-2) / 3 + (c-2)/3});
	cout<<ans<<endl;

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
