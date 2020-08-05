#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	int k = 0;
	if(n%4 == 0){
		k = n/4;
	} else {
		k = (n/4) + 1;
	}

	string ans="";
	for(int i=0;i<k;i++){
		ans+="8";
	}
	n -= k;
	for(int i=0;i<n;i++){
		ans = "9" + ans;
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
