#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int a,b,n;
	cin>>a>>b>>n;

	int mn = min(a,b), mx = max(a,b);
	int count = 0;
	// a = mn, b = mx;
	while(a <= n && b <= n){
		
		if(a < b){
			a+=b;
		} else {
			b+=a;
		}
		count+=1;
		// cout<<a<<" "<<b<<endl;
	}

	cout<<count<<endl;
	
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
