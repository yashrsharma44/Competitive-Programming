#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){

	int n;
	cin>>n;
	int ma  = INT_MAX, mb = INT_MAX;
	vector<int> a(n), b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma = min(ma, a[i]);
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		mb = min(mb, b[i]);
	}

	int count = 0;
	for(int i=0;i<n;i++){
		int d1 = a[i] - ma;
		int d2 = b[i] - mb;

		count += min(d1, d2) + abs(d1-d2);
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
