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

	set<int> elems;
	for(int i=0;i<=n+1;i++){
		elems.insert(i);
	}
	map<int,int> mp;
	for(int el : a){
		mp[el]+=1;
		elems.erase(el);
	}

	vector<int> ans(n, -1);
	for(int i=0;i<n;i++){

		ans[i] = *elems.begin();
		elems.erase(elems.begin());
		mp[a[i]]-=1;

		if(mp[a[i]] == 0){
			elems.insert(a[i]);
		}

	}

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
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
