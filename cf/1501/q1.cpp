#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	vector<vector<int>> ab(n, vector<int>(2, 0));
	for(int i=0;i<n;i++){
		cin>>ab[i][0]>>ab[i][1];
	}

	vector<int> tm(n);
	for(int i=0;i<n;i++) cin>>tm[i];

	int last = 0;
	int ans = -1;
	for(int i=0;i<n;i++){
		int time = ab[i][0];
		if(i > 0){
			time -= ab[i-1][1];
		}
		int delay = tm[i];

		int arr = last + time + delay;
		int delta = (ab[i][1] - ab[i][0] + 1) / 2;
		int dep = max(arr+delta, ab[i][1]);

		last = dep;
		ans = arr;
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