#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	sort(a.rbegin(), a.rend());
	for(int el : a){
		cout<<el<<" ";
	}
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
