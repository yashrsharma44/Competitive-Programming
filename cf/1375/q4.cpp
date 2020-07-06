#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

	int n;
	cin>>n;
	vector<int> a;
	map<int,int> mp;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		mp[vl]++;
		a.push_back(vl);
		
	}

	set<int> elems;
	for(int i=1;i<=n;i++){
		elems.insert(i);
	}

	for(int el : a){
		elems.erase(el);
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		int el = *elems.begin();
		int cp = a[el];

	}


	cout<<ans.size()<<endl;
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
