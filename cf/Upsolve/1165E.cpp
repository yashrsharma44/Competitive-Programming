#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	vector < int >a,b;
	
	for(int i=0;i<n;i++){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	for(int i=0;i<n;i++){
		int vl;
		cin>>vl;
		b.push_back(vl);
	}

	for(int i=0;i<n;i++){
		a[i] = a[i] * (i+1) * (n-i);
	}
	
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	sort(b.begin(),b.end());



	// vector<int> nw;
	// for(int i=0;i<n;i++){
	// 	nw.push_back(a[i]*b[i]);
	// }

	int ans = 0;
	for(int i=0;i<n;i++){
		a[i] = a[i] % MOD;
		ans = (ans + ((a[i] * b[i]) % MOD)) % MOD; 
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
