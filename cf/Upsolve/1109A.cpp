#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	vector<int> a;
	for(int i=0;i<n;i++){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector< vector<int> >count(2, vector<int>(1 << 20 + 3, 0));
	count[1][0] = 1;
	vector<int> prefix(n,0);
	prefix[0] = a[0];

	for(int i=1;i<n;i++){
		prefix[i] = prefix[i-1] ^ a[i];
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		ans += count[i%2][prefix[i]];
		count[i%2][prefix[i]]++;
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
