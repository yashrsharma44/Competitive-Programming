#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	n = 2*n;
	vector<int> a;
	while(n--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	set<int> elems;
	vector<int> ans;

	for(int el : a){
		if(elems.find(el) == elems.end()){
			ans.push_back(el);
			elems.insert(el);
		}
	}
	// cout<<ans.size()<<endl;
	for(int el : ans){
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
