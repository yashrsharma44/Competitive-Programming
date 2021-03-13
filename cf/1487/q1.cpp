#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	map<int,int> mp;
	int nn = n;
	set<int> a;
	while(nn--){
		int u; cin>>u;
		mp[u]++;
		a.insert(u);
	}

	int cnt = 0;
	int itr = 0;
	for(auto el : a){
		if(itr == 0){
			itr++;
			continue;
		}
		cnt += mp[el];
		itr++;
	}

	cout<<cnt<<endl;

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
