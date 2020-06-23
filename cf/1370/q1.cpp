#include <bits/stdc++.h>
#define int long long

using namespace std;

// vector<int> isprime(1000030, true);
// vector<int> SPF(1000030, true);
// vector<int> prime;

void solve(){

	int n;
	cin>>n;

	int ans = 1;
	for(int i=2;2*i<=n;i++){
		ans = max(ans, i);
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
