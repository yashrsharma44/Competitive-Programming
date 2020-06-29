#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n,k;
	cin>>n>>k;

	int nn = n;
	vector<int> a;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	map<int,int> mp;
	for(int el : a){
		mp[el % k] += 1;
	}
	if(mp.count(0) > 0 && mp[0] == n){
		cout<<0<<endl;
		return;
	}
	mp.erase(0);
	int max_ = 0;
	for(auto el : mp){
		int start = k - el.first;
		int size = el.second - 1;
		max_ = max(max_, start + (k*size));
	}

	cout<<(max_+1)<<endl;

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
