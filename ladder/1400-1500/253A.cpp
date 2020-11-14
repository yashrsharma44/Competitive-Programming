#include <bits/stdc++.h>
// #define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n, m; cin>>n>>m;
	string ans = "";
	if(n >= m){
		for(int i=0;i<m;i++){
			ans += "BG";
		}
		n = n - m;
		while(n > 0){
			ans += "B";
			n--;
		}
		
	} else {
		for(int i=0;i<n;i++){
			ans += "GB";
		}
		m = m - n;
		while(m > 0){
			ans += "G";
			m--; 
		}
	}
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
