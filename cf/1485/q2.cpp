#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n,q,k; cin>>n>>q>>k;
	vector<int> a;
	int nn = n;
	while(nn--){
		int val; cin>>val;
		a.push_back(val);
	}
	vector<vector<int>> qq;
	for(int i=0;i<q;i++){
		int u,v; cin>>u>>v;
		qq.push_back({u,v});
	}
	vector<int> pre({0});
	
	for(int i=0;i<n;i++){
		if(i == 0){
			int val = a[i+1] - 0 - 2;
			pre.push_back(val);
		} else if(i==n-1){
			int val = k - a[i-1] - 1;
			pre.push_back(val + pre.back());
		} else {
			int val = a[i+1] - a[i-1] - 2;
			pre.push_back(val + pre.back());
		} 
	}

	// for(int i=0;i<=n;i++) cout<<pre[i]<<" ";
	// cout<<endl;

	for(auto el : qq){

		if(el[0] == n || el[1] == 1){
			cout<<k - 1<<endl;
			continue;
		}
		int val = pre[el[1]-1] - pre[el[0]] + a[el[0]] - 2 + k - a[el[1]-2] - 1;
		cout<<val<<endl;
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
