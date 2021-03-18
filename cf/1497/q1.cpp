#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	sort(a.begin(), a.end());
	vector<int> b;
	cout<<a[0]<<" ";
	for(int i=1;i<n;i++){
		if(a[i] == a[i-1]){
			b.push_back(a[i]);
		} else {
			cout<<a[i]<<" ";
		}
	}
	for(auto el : b) cout<<el<<" ";

	cout<<endl;

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