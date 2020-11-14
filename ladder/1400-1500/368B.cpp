#include <bits/stdc++.h>
// #define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n, m; cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	map<int,int> ms;
	for(int el : arr) ms[el]++;

	vector<int> ans(n);
	for(int i=0;i<n;i++){
		ans[i] = ms.size();
		ms[arr[i]]--;
		if(ms[arr[i]] == 0){
			ms.erase(arr[i]);
		}
	}
	while(m--){
		int l; cin>>l;
		cout<<ans[l-1]<<endl;
	}

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
