#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005



void solve(){

	int n; cin>>n;
	vector<int> a(n);
	for(int &el : a) cin>>el;

	int sum = 0;
	for(int el : a) sum+=el;

	int ans = abs(sum - n);
	for(int i=2;i<=1e5+5;i++){
		int s2 = (int)pow(i, n) - 1;
		ans = min(ans, abs(sum - s2));
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
