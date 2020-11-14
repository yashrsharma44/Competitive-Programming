#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<vector<int>> arr(n);
	multiset<vector<int>> ms;
	for(int i=0;i<n;i++){
		int u,v; cin>>u>>v;
		arr[i] = {u,v};
	}
	// sort(arr.begin(), arr.end());

	for(auto el : arr) ms.insert(el);

	int L = INT_MAX, R = INT_MIN;
	for(auto el : arr){
		L = min(L, el[0]);
		R = max(R, el[1]);
	}
	// cout<<L<<" "<<R<<endl;
	for(int i=0;i<n;i++){
		auto el = arr[i];
		if(el[0] <= L && el[1] >= R){
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<-1<<endl;
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
