#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n,m; cin>>n>>m;
	vector<int>a(n);
	map<int,int> mp;

	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i] %= m;
		mp[a[i]]+=1;
	}

	int count = mp[0] > 0 ? 1 : 0;
	mp[0] = 0;
	for(int i=1;i<m;i++){
		if(mp[i] > 0 && 2 * i == m){
			count += 1;
			mp[i] = 0;
			continue;
		}
		int v1 = mp[i], v2 = mp[m - i];
		if(v1 > 0 && v2 > 0){
			if(v1 > v2){
				mp[m-i] -= v2;
				mp[i] -= (v2 + 1);
			} else if(v2 > v1){
				mp[i] -= v1;
				mp[m-i] -= (v1+1);
			} else {
				mp[i] = 0;
				mp[m-i] = 0;
			}
			count += 1;
		}
	}
	for(int i=0;i<m;i++){
		if(mp.count(i) > 0 && mp[i] != 0) count+=mp[i];
	}

	cout<<count<<endl;
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